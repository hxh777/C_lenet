# C_lenet
c语言推理lenet卷积神经网络
验证可用于工业玻璃划痕视觉检测

硬件平台i.mx6ull，软件环境linux内核4.1.5，
TFTLCD 7寸1024*600RGB屏幕，OV5640摄像头模块

C中代码具有模块性，可重复搭建RELU层，卷积层（含padding参数和stride参数），flatten层，最大值池化层，全连接层。
/******************************************************************************************************************/

各层参数

net=torch.nn.Sequential(

nn.Conv2d(1,6,kernel_size=5,padding=0),nn.ReLU(),

nn.MaxPool2d(kernel_size=2,stride=2),

nn.Conv2d(6,16,kernel_size=5,padding=0),nn.ReLU(),

nn.MaxPool2d(kernel_size=2,stride=2),nn.Flatten(),

nn.Linear(256,120),nn.ReLU(),

nn.Linear(120,84),nn.ReLU(),

nn.Linear(84,10)

各层输出

Conv2d output shape:	 torch.Size([1, 6, 24, 24])

ReLU output shape:		 torch.Size([1, 6, 24, 24])

MaxPool2d output shape:	 torch.Size([1, 6, 12, 12])

Conv2d output shape:	 torch.Size([1, 16, 8, 8])

ReLU output shape:		 torch.Size([1, 16, 8, 8])

MaxPool2d output shape:	 torch.Size([1, 16, 4, 4])

Flatten output shape:	 torch.Size([1, 256])

Linear output shape:	 torch.Size([1, 120])

ReLU output shape:		 torch.Size([1, 120])

Linear output shape:	 torch.Size([1, 84])

ReLU output shape:		 torch.Size([1, 84])

Linear output shape:	 torch.Size([1, 10])

/******************************************************************************************************************/
pytorch结果展示

![lenet1](https://user-images.githubusercontent.com/69228766/176351300-e1290ef3-8f9d-42a7-bb19-10b4b2dae37a.jpg)


基于ARMv7-A架构的SOC（NXP-I.MX6ULL）结果展示，交叉编译工具链(arm-poky-linux-gnueabi- )

![lenet2](https://user-images.githubusercontent.com/69228766/176351342-803125f5-4537-4ff2-a099-139cc44833de.jpg)


camke版本 cmake-3.16.0-Linux-X86_64
https://github.com/Kitware/CMake/releases，


工业玻璃划痕检测 用上述硬件平台可以实现正负样本分类，准确率可达98%。
![玻璃划痕1](https://user-images.githubusercontent.com/69228766/176351989-d9d8e046-7c59-49f0-9da0-e51d90256410.jpg)
![玻璃划痕2](https://user-images.githubusercontent.com/69228766/176352005-da817673-e130-4fec-bc0a-2d55f994b537.png)
