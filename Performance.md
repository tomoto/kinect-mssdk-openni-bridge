# Preliminary Performance Analysis #

Qualitatively speaking, the bridge access can be slower than the raw Kinect SDK access or the raw OpenNI access (with avin2 SensorKinect driver) because of the overhead for converting the entire frame from the Kinect SDK format to the OpenNI format.

You may be curious about how slow it is, but I do not really care for benchmarking because the final impact on the application should highly depend on the runtime condition (software, hardware, use case, etc.) and I doubt if the benchmark of the bridge could deserve to the effort. At least to me, it's OK as long as my Kinect Hacks work fine, and I would rather invest some money on a faster CPU than spending too much of my time on benchmarking and performance tuning of the bridge. :-)

Said that, I made a very quick preliminary experiment to amuse your (and my) curiosity. I roughly measured the latency of WaitNoneAndUpdateAll by calling it  every 30 milliseconds (= about the interval of the new frame's arrival at 30 FPS) on my Core i7 2600 CPU, and compared between the bridge access and the raw OpenNI access (with avin2 SensorKinect driver).

| **#** | **Condition** | **Raw OpenNI** | **Bridge** |
|:------|:--------------|:---------------|:-----------|
| (0) | No updated data | <10μs | <10μs |
| (1) | Depth only @640x480 | 280μs | 600μs |
| (2) | (1) + Image @640x480 | 480μs | 1000μs |
| (3) | (2) + Viewpoint Mapping | 540μs | 6000μs |
| (4) | (3) + NITE User Tracking | 8300μs | 9800μs |
| (5) | (3) + KinectSDK User Tracking | - | 3000μs |

  * (1)(2) indicates that the bridge can be 2 times slower than raw OpenNI with the simplest configuration. I cannot isolate the contributions from the bridge's overhead and Kinect SDK's performance, but anyways, this sub-millisecond difference would never bother me.
  * (3) looks a significant drawback of the bridge. The viewpoint mapping (transforming the depth frame into the RGB camera's coordinates) involves Kinect SDK API call of coordinate transformation (step1) and move of the depth data (step2). These steps have 5000μs overhead and the contribution seemed to be half-and-half, i.e. 2500μs for each.
  * (4) shows an interesting result. Although the benchmark process for this item includes the viewpoint mapping that made a large difference in the previous experiment, somehow it's gone when using the user tracking in mix.
  * (5) is the bridge's specific feature so there is no data for the raw OpenNI. It is faster probably because the depth frame's resolution internally drops down to 320x240 by enabling the user index. (It is KinectSDK's restriction.) Lower resolution would make the viewpoint mapping much faster.

Based on this preliminary result, I would say the latency impact on the client thread would be usually just a couple of milliseconds with a fast CPU like Core i7. But the difference might be significant in some conditions (I am not really sure of them) such as using the viewpoint mapping but no user tracking.

Note that the latency is not directly tied with the total CPU workload. For example, (3) may not necessarily mean the bridge is 10 times heavier just because the latency of WaitNoneAndUpdateAll is 10 times longer. The bridge calculates the viewpoint mapping in the client's (caller of WaitNoneAndUpdateAll's) thread which directly extends the latency, but I guess avin2's SensorKinect may be calculating the same in the data generation thread. So, it may be a matter of efficiency of the multi-processor utilization but maybe not the difference of the total CPU workload. So, when you say "slow", you should be very clear what it means.