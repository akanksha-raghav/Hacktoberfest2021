import cv2 as cv

img = cv.imread('./bone.jpeg')  #read image
dimensions = img.shape  #get image dimensions

# ==================== Gray Image ======================
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('Original', gray)  # gray image
print(dimensions)
# Find the highest range(L-1) of gray level in the range [0, L-1] from the image
L = 256
max_gray_level = L - 1  #L-1

a = 100  # int(input('Enter the value of a: '))
b = 150  # int(input('Enter the value of b: '))
# gray level slicing
gray_level_slicing = gray.copy()
for row in range(dimensions[0]):
    for col in range(dimensions[1]):
        if (gray[row][col] >= a) and (gray[row][col] <= b):
            gray_level_slicing[row][col] = max_gray_level
        else:
            gray_level_slicing[row][col] = 0
cv.imshow('Gray Level Slicing Without Bg', gray_level_slicing)

gray_level_slicing_bg = gray.copy()
for row in range(dimensions[0]):
    for col in range(dimensions[1]):
        if (gray[row][col] >= a) and (gray[row][col] <= b):
            gray_level_slicing_bg[row][col] = max_gray_level
cv.imshow('Gray Level Slicing With Bg', gray_level_slicing_bg)

cv.waitKey(0)
cv.destroyAllWindows()