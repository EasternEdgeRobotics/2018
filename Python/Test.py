import numpy as np
import cv2
import argparse
from matplotlib import pyplot

#links
#https://docs.opencv.org/3.0-beta/doc/py_tutorials/py_tutorials.html
#https://www.marinetech.org/files/marine/files/ROV%20Competition/2018%20competition/Missions/Aircraft/EXPLORER%20Tail%20Handbook%202.pdf



#This turns on deafult camera on computer and begins reading from it
cam = cv2.VideoCapture(0)



#color value boundaries organized by color
#       - looks for GBR values in this range
blueBoundaries=[
    #  G   B   R  to->  G   B   R
    ([17, 15, 100], [50, 56, 200]),
    ([86, 31, 4], [220, 88, 50]),
]

redBoundaries=[
    ([26, 37, 84], [19, 45, 141]),
    ([70, 60, 80], [70, 103, 195])
]

yellowBoundaries=[
    ([25, 146, 190], [62, 174, 250]),
    ([5, 172, 188], [180, 200, 170])
]

#combines all boundaries into one list
allBoundaries = blueBoundaries + redBoundaries + yellowBoundaries



while True:
    ret_val, img = cam.read()       #this gets the frame of the camera at this time
    img = cv2.flip(img, 1)          #flips image horizontally so it makes sense

    outputImage = 0                 #init of the outputImage
    allmask = 0                     #init of variable to contain all masks

    #loop to go from lower to upper of every bound
    for(lower, upper) in allBoundaries:
        lower = np.array(lower, dtype= 'uint8')  #change to proper value type
        upper = np.array(upper, dtype= 'uint8')

        mask = cv2.inRange(img, lower, upper)    #creating a mask of only pixels that have color in range
        allmask += mask                          #adds this mask to all maskes to be rendered
        
    outputImage = cv2.bitwise_and(img, img, mask = allmask)   
    cv2.imshow('cam', np.hstack([img, outputImage]))     #displays image with masks added

    if cv2.waitKey(1) == 27:          #if ESC is pressed, quit program
        break;
        


cv2.destroyAllWindows()
