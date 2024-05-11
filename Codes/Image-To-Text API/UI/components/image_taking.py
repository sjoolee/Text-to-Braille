import cv2
import time

def image_taking():

    print("Printing in...3")
    time.sleep(1)
    print("2")
    time.sleep(1)
    print("1")
    cam = cv2.VideoCapture(0)

    result, image = cam.read()

    if result: 
    
        cv2.imwrite("./UI/images/temp.png", image) 
    
    else: 
        print("No image detected. Please! try again") 
