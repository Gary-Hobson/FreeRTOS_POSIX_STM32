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

![](./Doc/picture/POSIX.jpg) 

## FreeRTOS_POSIX_STM32

该文件为在STM32移植 FreeRTOS POSIX 接口，

使用 STM32CubeMX 配置生成工程，然后将VS相关文件添加到 keil 工程