# FreeRTOS_POSIX
在 FreeRTOS 上使用 POSIX 接口，使用 POSIX 接口作为嵌入式软件的隔离层。

该仓库参考 [FreeRTOS-POSIX](https://www.freertos.org/FreeRTOS-Plus/FreeRTOS_Plus_POSIX/index.html#supported_features) 官网，并将其移植到STM32

> 开发环境：
>
> Keil 5.33 + ARMCC  V5.06
>
> STM32CubeMX 6.11 +  HAL 库 V1.83
>
> 硬件 ：
>
> STM32F103ZET6
>
> 内部RC 64M 、串口波特率 115200
>
> PE5 系统运行指示灯、PB5任务运行指示灯

---

## FreeRTOS_POSIX_Simulation

该文件夹为 FreeRTOS 提供的 VS 工程，在VS环境中运行 FreeRTOS ，并实现 POSIX 接口访问。

**整体架构图：**

![](./Document/Picture/POSIX.jpg)

## FreeRTOS_Linux_Simulator

Linux 模拟器工程位于 `Projects/FreeRTOS_Linux_Simulator`，基于 FreeRTOS 官方 `FreeRTOS/Demo/Posix_GCC` demo，并使用 FreeRTOS Kernel 的 POSIX/Linux port 在 Linux 主机上运行。

构建和运行：

```sh
cd Projects/FreeRTOS_Linux_Simulator
make clean
make USER_DEMO=BLINKY_DEMO
./build/posix_demo
```

当前同步的上游版本：

- FreeRTOS Kernel: https://github.com/FreeRTOS/FreeRTOS-Kernel.git `V11.3.0` / `9b777ae5c5b8e9e456065a00294d1e5f5f9facf5`
- FreeRTOS Linux demo: https://github.com/FreeRTOS/FreeRTOS/tree/main/FreeRTOS/Demo/Posix_GCC latest HEAD `f60e36e45d0d7ea84febc8d1ea5f4e70f68cb3ec`
- FreeRTOS Kernel Partner-Supported-Ports: https://github.com/FreeRTOS/FreeRTOS-Kernel-Partner-Supported-Ports.git `abc22103e1e6634b33457d4127bff1ab62f27f90`
- FreeRTOS Kernel Community-Supported-Ports: https://github.com/FreeRTOS/FreeRTOS-Kernel-Community-Supported-Ports.git `bae4c7aa19009825ba48071a8fe25dcb8be84880`
- FreeRTOS+POSIX: `FreeRTOS/POSIX`, from https://github.com/FreeRTOS/Lab-Project-FreeRTOS-POSIX.git latest HEAD `14ee4b2c7c34f2663c6f083080d3e4a2d30171ec`

参考文档：

- FreeRTOS Linux simulator: https://freertos.org/Documentation/02-Kernel/03-Supported-devices/04-Demos/03-Emulation-and-simulation/Linux/FreeRTOS-simulator-for-Linux
- FreeRTOS+POSIX: https://freertos.org/FreeRTOS-Plus/FreeRTOS_Plus_POSIX/

## FreeRTOS_POSIX_STM32

该文件为在STM32移植 FreeRTOS POSIX 接口，

使用 STM32CubeMX 配置生成工程，然后将VS相关文件添加到 keil 工程
