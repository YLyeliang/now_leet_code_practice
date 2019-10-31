import cv2
img=cv2.imread("D:\data\stitch_test\stitch_before_det/Line17_up_20190411032509_29_34km+484.7m_forward.jpg")
img2=cv2.resize(img,(1000,600))
cv2.imshow("ah",img2)
cv2.waitKey()