import torch
import torch.nn.functional as F
import numpy as np


def l1_loss_np(output, target):
    loss = 0
    for o, t in zip(output, target):
        loss += np.abs(o-t)
    return loss/len(output)


def l2_loss_np(output, target):
    loss = 0
    for o, t in zip(output, target):
        loss += np.power((o-t), 2)
    return loss/len(output)


def smooth_l1_loss_np(output, target):
    loss = 0
    for o, t in zip(output, target):
        if np.abs(o-t) < 1:
            loss += 0.5*np.power((o-t), t)
        else:
            loss += np.abs(o-t) - 0.5
    return loss/len(output)


if __name__ == "__main__":
    y = np.array([8, 18, 28, 38])
    y_hat = np.array([10, 20, 30, 40])
    print("L1 and L2 loss")
    print(l1_loss_np(y, y_hat))
    print(F.l1_loss(torch.Tensor(y_hat), torch.Tensor(y)))
    print(l2_loss_np(y_hat, y))
    print(F.mse_loss(torch.Tensor(y_hat), torch.Tensor(y)))

    print("smooth L1 loss")
    print(smooth_l1_loss_np(y, y_hat))
    print(F.smooth_l1_loss(torch.Tensor(y_hat), torch.Tensor(y)))
