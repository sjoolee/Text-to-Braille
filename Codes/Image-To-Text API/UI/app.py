from components.image_reading import image_reading
from components.image_taking import image_taking
from PIL import ImageTk, Image as PILImage
from tkinter import *
import customtkinter
import serial
import time

# Establish serial connection with Arduino
ser = serial.Serial('COM6', 9600)

#color palette
bg_color = "#121212"
button_color = "#BB86FC"
button_text = "#000000"

class main_menu(customtkinter.CTk):

    def __init__(self):
        super().__init__()
        self.title("Braille Translation Device")
        self.geometry("600x700")
        self.config(bg=bg_color)
        self._create_function_screen()
        self.resizable(height=False, width=False)

    def _create_function_screen(self):
        #fonts
        font_buttons = customtkinter.CTkFont(family="Lexend SemiBold", size=12)
        font_labels = customtkinter.CTkFont(family="Lexend", weight="bold", size=20)

        take_image_button = customtkinter.CTkButton(self, text="Take Image", text_color=button_text, fg_color=button_color, bg_color=bg_color, font=font_buttons, command=self._take_image)
        take_image_button.place(relx=0.35, rely=0.35, anchor=CENTER)

        read_image_button = customtkinter.CTkButton(self, text="Read Image", text_color=button_text, fg_color=button_color, bg_color=bg_color, font=font_buttons, command=self._read_image)
        read_image_button.place(relx=0.65, rely=0.35, anchor=CENTER)

        # Bind hover events for take_image_button
        take_image_button.bind("<Enter>", lambda event: take_image_button.configure(bg_color="#1f1f1f"))
        take_image_button.bind("<Leave>", lambda event: take_image_button.configure(bg_color=bg_color))

        # Bind hover events for read_image_button
        read_image_button.bind("<Enter>", lambda event: read_image_button.configure(bg_color="#1f1f1f"))
        read_image_button.bind("<Leave>", lambda event: read_image_button.configure(bg_color=bg_color))

        customtkinter.CTkLabel(self, text=" ", image=self._load_logo('./UI/images/logo.png'), bg_color=bg_color).place(relx=0.50, rely=0.1, anchor=CENTER)
        customtkinter.CTkLabel(self, text="Braille Translation Device", font=font_labels, bg_color=bg_color).place(relx=0.50, rely=0.2, anchor=CENTER)

    def _take_image(self):
        image_taking()
        customtkinter.CTkLabel(self, text=" ", image=self._load_image('./UI/images/temp.png')).place(relx=0.5, rely=0.6, anchor=CENTER)

    def _read_image(self):
        font_labels = customtkinter.CTkFont(family="Lexend", weight="bold", size=20)
        results = image_reading('./UI/images/temp.png')
        customtkinter.CTkLabel(self, text=results, font=font_labels, bg_color=bg_color).place(relx=0.5, rely=0.8, anchor=CENTER)
       # Convert the list of results to a string separated by a comma
        results_str = ','.join(map(str, results))

        # Send the results over serial
        ser.write(results_str.encode())

    def _load_image(self, image_path):
        img = PILImage.open(image_path)
        img = img.resize((300, 200), PILImage.NEAREST)
        return ImageTk.PhotoImage(img)

    def _load_logo(self, image_path):
        img = PILImage.open(image_path)
        img = img.resize((100, 100), PILImage.NEAREST)
        return ImageTk.PhotoImage(img)

# Create an instance of the main_menu class
if __name__ == "__main__":
    app = main_menu()
    app.mainloop()
    ser.close()