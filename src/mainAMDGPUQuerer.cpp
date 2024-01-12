
/// \file mainPerfGPUMetrics.cpp
/// \brief Demonstrates how to control GPU metrics when programming with ADLX.

#include "SDK/ADLXHelper/Windows/Cpp/ADLXHelper.h"
#include "SDK/Include/IPerformanceMonitoring.h"
#include <iostream>
#include <string>

// Use ADLX namespace
using namespace adlx;

// ADLXHelper instance
// No outstanding interfaces from ADLX must exist when ADLX is destroyed.
// Use global variables to ensure validity of the interface.
static ADLXHelper g_ADLXHelp;

// ASCII °
static const signed char g_degree = 248;


// Wait for exit with error message
void WaitAndExit(std::string msg)
{
    // Printout the message and pause to see it before returning the desired code
    if (msg.compare("") != 0)
        std::cout << msg << std::endl;

    system("pause");
}


// Display the system time stamp (in ms)
void GetTimeStamp(IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_int64 timeStamp = 0;
    ADLX_RESULT res = gpuMetrics->TimeStamp(&timeStamp);
    if (ADLX_SUCCEEDED(res))
        std::cout << "The GPU timp stamp is: " << timeStamp << "ms" << std::endl;
}

// Display GPU usage (in %)
void ShowGPUUsage(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics, adlx_bool verbose = true)
{
    adlx_bool supported = false;
    // Display GPU usage support status
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUUsage(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        if (supported)
        {
            adlx_double usage = 0;
            res = gpuMetrics->GPUUsage(&usage);
            if (ADLX_SUCCEEDED(res))
            {
                if (verbose)
                {
                    std::cout << "GPU usage support status: " << supported << std::endl;
                    std::cout << "The GPU usage is: " << usage << "%" << std::endl;
                } else {
                    std::cout << usage << std::endl;
                }
            }
        } else {
            std::cout << "ERROR: GPU usage query not supported" << std::endl;
        }
    }
}

// Display GPU clock speed (in MHz)
void ShowGPUClockSpeed(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;
    // Display GPU clock speed support status
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUClockSpeed(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        std::cout << "GPU clock speed support status: " << supported << std::endl;
        if (supported)
        {
            adlx_int gpuClock = 0;
            res = gpuMetrics->GPUClockSpeed(&gpuClock);
            if (ADLX_SUCCEEDED(res))
                std::cout << "The GPU clock speed is: " << gpuClock << "MHz" << std::endl;
        }
    }
}

// Display GPU VRAM clock speed (in MHz)
void ShowGPUVRAMClockSpeed(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;
    // Display the GPU VRAM clock speed support status
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUVRAMClockSpeed(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        std::cout << "GPU VRAM clock speed support status: " << supported << std::endl;
        if (supported)
        {
            adlx_int memoryClock = 0;
            res = gpuMetrics->GPUVRAMClockSpeed(&memoryClock);
            if (ADLX_SUCCEEDED(res))
                std::cout << "The GPU VRAM clock speed is: " << memoryClock << "MHz" << std::endl;
        }
    }
}

// Display GPU temperature(in °C)
void ShowGPUTemperature(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics, adlx_bool verbose = true)
{
    adlx_bool supported = false;

    // Display the GPU temperature support status
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUTemperature(&supported);
    if (ADLX_SUCCEEDED(res))
    {

        if (supported)
        {
            adlx_double temperature = 0;
            res = gpuMetrics->GPUTemperature(&temperature);
            if (ADLX_SUCCEEDED(res))
            {
                if (verbose)
                {
                    std::cout << "GPU temperature support status: " << supported << std::endl;
                    std::cout << "The GPU temperature is: " << temperature << g_degree <<"C" << std::endl;
                } else {
                    std::cout << temperature << std::endl;
                }
            }
        } else {
            std::cout << "ERROR: GPU VRAM query not supported" << std::endl;
        }
    }
}

// Display GPU hotspot temperature(in °C)
void ShowGPUHotspotTemperature(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;

    // Display GPU hotspot temperature support status
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUHotspotTemperature(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        std::cout << "GPU hotspot temperature support status: " << supported << std::endl;
        if (supported)
        {
            adlx_double hotspotTemperature = 0;
            res = gpuMetrics->GPUHotspotTemperature(&hotspotTemperature);
            if (ADLX_SUCCEEDED(res))
                std::cout << "The GPU hotspot temperature is: " << hotspotTemperature << g_degree <<"C" << std::endl;
        }
    }
}

// Display GPU power(in W)
void ShowGPUPower(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;
    // Display GPU power support status
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUPower(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        std::cout << "GPU power support status: " << supported << std::endl;
        if (supported)
        {
            adlx_double power = 0;
            res = gpuMetrics->GPUPower(&power);
            if (ADLX_SUCCEEDED(res))
                std::cout << "The GPU power is: " << power << "W" << std::endl;
        }
    }
}

// Display GPU total board power(in W)
void ShowGPUTotalBoardPower(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;
    // Display GPU total board power support status
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUTotalBoardPower(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        std::cout << "GPU total board power support status: " << supported << std::endl;
        if (supported)
        {
            adlx_double power = 0;
            res = gpuMetrics->GPUTotalBoardPower(&power);
            if (ADLX_SUCCEEDED(res))
                std::cout << "The GPU total board power is: " << power << "W" << std::endl;
        }
    }
}

// Display GPU intake temperature(in °C)
void ShowGPUIntakeTemperature (IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;

    // Display the GPU temperature support status
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUIntakeTemperature (&supported);
    if (ADLX_SUCCEEDED (res))
    {
        std::cout << "GPU intake temperature support status: " << supported << std::endl;
        if (supported)
        {
            adlx_double temperature = 0;
            res = gpuMetrics->GPUIntakeTemperature (&temperature);
            if (ADLX_SUCCEEDED (res))
                std::cout << "The GPU intake temperature is: " << temperature << g_degree << "C" << std::endl;
        }
    }
}

// Display GPU fan speed (in RPM)
void ShowGPUFanSpeed(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;
    // Display GPU fan speed support status
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUFanSpeed(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        std::cout << "GPU fan speed support status: " << supported << std::endl;
        if (supported)
        {
            adlx_int fanSpeed = 0;
            res = gpuMetrics->GPUFanSpeed(&fanSpeed);
            if (ADLX_SUCCEEDED(res))
                std::cout << "The GPU fan speed is: " << fanSpeed << "RPM" << std::endl;
        }
    }
}

// Display GPU VRAM (in MB)
void ShowGPUVRAM(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics, adlx_bool verbose = true)
{
    adlx_bool supported = false;
    // Display GPU VRAM support status
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUVRAM(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        if (supported)
        {
            adlx_int VRAM = 0;
            res = gpuMetrics->GPUVRAM(&VRAM);
            if (ADLX_SUCCEEDED(res))
            {
                if (verbose)
                {
                    std::cout << "GPU VRAM support status: " << supported << std::endl;
                    std::cout << "The GPU VRAM is: " << VRAM << "MB" << std::endl;
                } else {
                    std::cout << VRAM << std::endl;
                }
            }
        } else {
            std::cout << "ERROR: GPU VRAM query not supported" << std::endl;
        }
    }
}

// Display GPU Voltage (in mV)
void ShowGPUVoltage(IADLXGPUMetricsSupportPtr gpuMetricsSupport, IADLXGPUMetricsPtr gpuMetrics)
{
    adlx_bool supported = false;
    // Display GPU voltage support status
    ADLX_RESULT res = gpuMetricsSupport->IsSupportedGPUVoltage(&supported);
    if (ADLX_SUCCEEDED(res))
    {
        std::cout << "GPU voltage support status: " << supported << std::endl;
        if (supported)
        {
            adlx_int voltage = 0;
            res = gpuMetrics->GPUVoltage(&voltage);
            if (ADLX_SUCCEEDED(res))
                std::cout << "The GPU voltage is: " << voltage << "mV" << std::endl;
        }
    }
}



int main(int argc, char* argv[])
{
    adlx_bool verbose = false;
    if (argc == 3 && std::string(argv[2]).compare("-v") == 0) {
        verbose = true;
    }

    std::string error_message = "";
    adlx_double exit_code = 0;

    ADLX_RESULT res = ADLX_FAIL;

    // Initialize ADLX
    res = g_ADLXHelp.Initialize();

    if (ADLX_SUCCEEDED(res))
    {
        // Get Performance Monitoring services
        IADLXPerformanceMonitoringServicesPtr perfMonitoringService;
        res = g_ADLXHelp.GetSystemServices()->GetPerformanceMonitoringServices(&perfMonitoringService);
        if (ADLX_SUCCEEDED(res))
        {
            IADLXGPUListPtr gpus;
            // Get GPU list
            res = g_ADLXHelp.GetSystemServices()->GetGPUs(&gpus);
            if (ADLX_SUCCEEDED(res))
            {
                // Use the first GPU in the list
                IADLXGPUPtr oneGPU;
                res = gpus->At(gpus->Begin(), &oneGPU);
                if (ADLX_SUCCEEDED(res))
                {
                    // Get GPU metrics support
                    IADLXGPUMetricsSupportPtr gpuMetricsSupport;
                    ADLX_RESULT res1 = perfMonitoringService->GetSupportedGPUMetrics(oneGPU, &gpuMetricsSupport);

                    // Get current GPU metrics
                    IADLXGPUMetricsPtr gpuMetrics;
                    ADLX_RESULT res2 = perfMonitoringService->GetCurrentGPUMetrics(oneGPU, &gpuMetrics);

                    // Display timestamp and GPU metrics
                    if (ADLX_SUCCEEDED(res1) && ADLX_SUCCEEDED(res2))
                    {
                        if (argc == 1) {
                            std::cout << "The current GPU metrics: " << std::endl;
                            std::cout << std::boolalpha;  // Display boolean variable as true or false
                            GetTimeStamp(gpuMetrics);
                            ShowGPUUsage(gpuMetricsSupport, gpuMetrics);
                            ShowGPUClockSpeed(gpuMetricsSupport, gpuMetrics);
                            ShowGPUVRAMClockSpeed(gpuMetricsSupport, gpuMetrics);
                            ShowGPUTemperature(gpuMetricsSupport, gpuMetrics);
                            ShowGPUHotspotTemperature(gpuMetricsSupport, gpuMetrics);
                            ShowGPUPower(gpuMetricsSupport, gpuMetrics);
                            ShowGPUFanSpeed(gpuMetricsSupport, gpuMetrics);
                            ShowGPUVRAM(gpuMetricsSupport, gpuMetrics);
                            ShowGPUVoltage(gpuMetricsSupport, gpuMetrics);
                            ShowGPUTotalBoardPower(gpuMetricsSupport, gpuMetrics);
                            ShowGPUIntakeTemperature (gpuMetricsSupport, gpuMetrics);
                            std::cout << std::noboolalpha;
                        } else {
                            if (std::string(argv[1]).compare("--gpu_usage") == 0) {
                                ShowGPUUsage(gpuMetricsSupport, gpuMetrics, verbose);
                            } else if (std::string(argv[1]).compare("--gpu_mem_usage") == 0) {
                                ShowGPUVRAM(gpuMetricsSupport, gpuMetrics, verbose);
                            } else if (std::string(argv[1]).compare("--gpu_temp") == 0) {
                                ShowGPUTemperature(gpuMetricsSupport, gpuMetrics, verbose);
                            } else {
                                std::cout << "Argument `" << argv[1] << "` is not reconised." << std::endl;
                            }
                        }
                    }
                }
                else {
                    error_message = "Get particular GPU failed";
                    exit_code = 4;
                }
            }
            else {
                error_message = "Get GPU list failed";
                exit_code = 3;
            }
        }
        else {
            error_message = "Get performance monitoring services failed";
            exit_code = 2;
        }
    }
    else {
        error_message = "g_ADLXHelp initialize failed";
        exit_code = 1;
    }

    if (exit_code !=0) {
        std::cout << error_message << std::endl;
        return exit_code;
    }
    // Destroy ADLX
    res = g_ADLXHelp.Terminate();

    return 0;
}