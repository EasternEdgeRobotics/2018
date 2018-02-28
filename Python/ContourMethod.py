import numpy as np
import cv2

cam = cv2.VideoCapture(0)

#color limits for isolating color on camera.
Boundaries=[
    #  G   B   R  to->  G   B   R
    ([17, 15, 100], [50, 56, 200]),
    ([86, 31, 4], [220, 88, 50]),
    ([35,40,110],[50,50,200])
]

#ranges for detection of color -----NEEDS ADJUSTMENT
b1 = range(110,150)
b2 = range(70, 88)
b3 = range(30, 50)

r1 = range(40, 50)
r2 = range(35, 50)
r3 = range(110, 200)


#function that checks the ranges for color detection and returns String of color name
def whatColor(col):
    if col[0] in b1 and col[1] in b2 and col[2] in b3:
        return "BLUE"
    elif col[0] in r1 and col[1] in r2 and col[2] in r3:
        return "RED"

#continueous while loop
while True:
    ret, img = cam.read()  #get frame of main camera
    img = cv2.flip(img, 1) 
    
    allmask = 0   #init mask variable
    
    for(lower, upper) in Boundaries:
        lower = np.array(lower, dtype= 'uint8')  #change to proper value type
        upper = np.array(upper, dtype= 'uint8')

        mask = cv2.inRange(img, lower, upper)    #creating a mask of only pixels that have color in range
        allmask += mask

    imgout = cv2.bitwise_and(img, img, mask=allmask)   #applies mask to display image showing only that color
    im2, contours, hierarchy = cv2.findContours(allmask, cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    #^ finds all the contours in the mask and assisns them to the contours variable

    for i in range(0,len(contours)):       #looping through all detected contours
        c = contours[i]
        M = cv2.moments(c)
        X = 0
        Y = 0
        if(M['m00'] > 0):
            X = int(M['m10']/M['m00'])     #finding the center of the contour
            Y = int(M['m01']/M['m00'])
        col = imgout[Y,X]   #gets colour at center of contour
        if col[0] != 0 and cv2.contourArea(c) > 300:
            #^    checks if contours colour doesn't equal zer0. If it's zero, the colour is black.
            #  Because the mask removes the colours except the ones we want, if it's not black, it's a proper contour
            cv2.drawContours(imgout, contours, i, (0,255,0), 3)
            
            shape = "???"   #init variable for shape
            peri = cv2.arcLength(c, True)   #checks for vertices on contour
            approx = cv2.approxPolyDP(c, 0.04 * peri, True)
            if len(approx) == 3:
                shape = "TRIANGLE"
            elif len(approx) == 4:
                shape = "RECTANGLE"

            #drawing text for colour and shape
            cv2.putText(imgout, whatColor(col), (5,90), cv2.FONT_HERSHEY_SIMPLEX, 2, 255)
            cv2.putText(imgout, shape, (5,180), cv2.FONT_HERSHEY_SIMPLEX, 2, 255)
            break
	    
    cv2.imshow('cam', imgout)  #show image

    if cv2.waitKey(1) == 27:
        break;

cv2.destroyAllWindows()
