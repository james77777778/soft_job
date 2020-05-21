from PIL import Image
import numpy as np
import torch
import torchvision.transforms.functional as TF

img = Image.open("sample.jpg")
img = TF.resize(img, (256, 256))
img_tensor = TF.to_tensor(img)

# shift operation (x: +50, y: +100)
theta = np.array([
    [1, 0, 50],
    [0, 1, 100]
])
t1 = theta[:, [0, 1]]
t2 = theta[:, [2]]

shifted_tensor = torch.zeros_like(img_tensor)
for x in range(img_tensor.size(1)):
    for y in range(img_tensor.size(2)):
        pos = np.array([[x], [y]])
        npos = t1@pos+t2
        nx, ny = npos[0][0], npos[1][0]
        if 0 <= nx < img_tensor.size(1) and 0 <= ny < img_tensor.size(2):
            shifted_tensor[:, nx, ny] = img_tensor[:, x, y]
shifted_img = TF.to_pil_image(shifted_tensor)

# scaling operation (x2)
theta = np.array([
    [2, 0, 0],
    [0, 2, 0]
])
t1 = theta[:, [0, 1]]
t2 = theta[:, [2]]

shifted_tensor = torch.zeros_like(img_tensor)
for x in range(img_tensor.size(1)):
    for y in range(img_tensor.size(2)):
        pos = np.array([[x], [y]])
        npos = t1@pos+t2
        nx, ny = npos[0][0], npos[1][0]
        if 0 <= nx < img_tensor.size(1) and 0 <= ny < img_tensor.size(2):
            shifted_tensor[:, nx, ny] = img_tensor[:, x, y]
shifted_img = TF.to_pil_image(shifted_tensor)

# rotating operation (30 degree)
angle = -30/180*np.pi
theta = np.array([
    [np.cos(angle), -np.sin(angle), 0],
    [np.sin(angle), np.cos(angle), 0]
])
t1 = theta[:, [0, 1]]
t2 = theta[:, [2]]

shifted_tensor = torch.zeros_like(img_tensor)
for x in range(img_tensor.size(1)):
    for y in range(img_tensor.size(2)):
        pos = np.array([[x], [y]])
        npos = t1@pos+t2
        nx, ny = int(npos[0][0]), int(npos[1][0])
        if 0 <= nx < img_tensor.size(1) and 0 <= ny < img_tensor.size(2):
            shifted_tensor[:, nx, ny] = img_tensor[:, x, y]
shifted_img = TF.to_pil_image(shifted_tensor)

# combine scale and rotate
angle = -30/180*np.pi
theta = np.array([
    [0.5*np.cos(angle), 0.5*-np.sin(angle), 0],
    [0.5*np.sin(angle), 0.5*np.cos(angle), 0]
])
t1 = theta[:, [0, 1]]
t2 = theta[:, [2]]

shifted_tensor = torch.zeros_like(img_tensor)
for x in range(img_tensor.size(1)):
    for y in range(img_tensor.size(2)):
        pos = np.array([[x], [y]])
        npos = t1@pos+t2
        nx, ny = int(npos[0][0]), int(npos[1][0])
        if 0 <= nx < img_tensor.size(1) and 0 <= ny < img_tensor.size(2):
            shifted_tensor[:, nx, ny] = img_tensor[:, x, y]
shifted_img = TF.to_pil_image(shifted_tensor)
