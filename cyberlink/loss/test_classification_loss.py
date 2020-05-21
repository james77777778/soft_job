import torch
import torch.nn.functional as F
import numpy as np


def binary_cross_entropy_np(output, target):
    loss = -np.sum(target*np.log(output)+(1.-target)*np.log(1.-output))
    return loss/output.shape[0]


def cross_entropy_np(output, target):
    loss = 0
    for i in range(output.shape[0]):
        loss += -np.log(
            np.exp(output[i, target[i]])/np.sum(np.exp(output[i, :]))
        )
    return loss/output.shape[0]


if __name__ == "__main__":
    y = np.array([1., 0., 0., 1.])
    y_hat = np.array([0.8, 0.1, 0.9, 0.15])
    print("binary cross entropy loss")
    print(binary_cross_entropy_np(y_hat, y))
    print(F.binary_cross_entropy(torch.Tensor(y_hat), torch.Tensor(y)))

    print("multi-class cross entropy loss")
    y = np.array([1, 2, 0, 2])
    y_hat = np.array([
        [0.1, 0.8, 0.1],
        [0.05, 0.2, 0.75],
        [0.9, 0.05, 0.05],
        [0.05, 0.2, 0.75]
    ])
    print(F.cross_entropy(torch.Tensor(y_hat), torch.Tensor(y).long()))
    print(cross_entropy_np(y_hat, y))
