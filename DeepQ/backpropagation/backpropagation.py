import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F


'''
Linear
'''
x = torch.tensor([
    [1, 2, 3],
], dtype=torch.float)

w = torch.tensor([
    [1, 1, 1],
    [0, 0, 0]
], dtype=torch.float)

y = torch.tensor([
    [8, 1],
])

linear = nn.Linear(3, 2, bias=False)
with torch.no_grad():
    linear.weight.copy_(w)

loss = torch.mean(torch.abs(linear(x)-y))
loss.backward()
print(linear.weight.grad)
'''
tensor([[-0.5000, -1.0000, -1.5000],
        [-0.5000, -1.0000, -1.5000]])
dL/dw_1 = dL/do_1 * do_1/dw_1 = 0.5 * 1 = 0.5
L = (o_1 + o_2) / 2
o1 = [1] * w_1
'''

linear.zero_grad()
x = torch.tensor([
    [4, 5, 6],
], dtype=torch.float)

y = torch.tensor([
    [14, -1],
])
loss = torch.mean(torch.abs(linear(x)-y))
loss.backward()
print(linear.weight.grad)
'''
tensor([[2.0000, 2.5000, 3.0000],
        [2.0000, 2.5000, 3.0000]])
dL/dw_1 = dL/do_1 * do_1/dw_1 = 0.5 * 4 = 2.0
L = (o_1 + o_2) / 2
o1 = [4] * w_1
'''

'''
CNN
'''
x = torch.tensor([[[
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]]], dtype=torch.float)

w = torch.tensor([
    [1, 2],
    [3, 4]
], dtype=torch.float)

cnn = nn.Conv2d(1, 1, kernel_size=2, stride=1, bias=False)
with torch.no_grad():
    cnn.weight.copy_(w)

y_hat = cnn(x)
print(y_hat)
'''
tensor([[[[37., 47.],
          [67., 77.]]]], grad_fn=<MkldnnConvolutionBackward>)
37 = 1*1+2*2+4*3+5*4
'''
