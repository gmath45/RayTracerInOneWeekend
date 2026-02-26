## [Ray Tracing in One Weekend](https://github.com/gmath45/Graphics-Programming/RayTracerInOneWeekend)

---

I had been going back-and-forth as to what book or project I should start showcasing, so I've decided on starting this one! ([Ray Tracing in One Weekend - Peter Shirley, Trevor David Black, Steve Hollasch](https://raytracing.github.io/books/RayTracingInOneWeekend.html))

### Tools:
 - C++11
 - CMake

### Files:
> #### [Hello Color](PPMs/image.ppm):
> ---
> - `color.h`
> - `ray.h`
> - `vec3.h`
> - `main.cpp` \
> [![Hello Color](PPMs/image.png "Hello Color")](PPMs/image.ppm)

> #### [Blue & White 'Sky'](PPMs/sky.ppm):
> ---
> - `color.h`
> - `ray.h`
> - `vec3.h`
> - `main.cpp` \
> [![Sky](PPMs/sky.png "Blue & White 'Sky'")](PPMs/sky.ppm)

> #### [Red Sphere (Unshaded)](PPMs/sphere.ppm):
> ---
> - `color.h`
> - `ray.h`
> - `vec3.h`
> - `sphere.cpp` \
> [![Sphere](PPMs/sphere.png "Red Sphere (Unshaded)")](PPMs/sphere.ppm)

> #### [Red Sphere (Shaded)](PPMs/sphere_shaded.ppm):
> ---
> - `color.h`
> - `ray.h`
> - `vec3.h`
> - `sphere_shaded.cpp` \
> [![Shaded Sphere](PPMs/sphere_shaded.png "Red Sphere (Shaded)")](PPMs/sphere_shaded.ppm)

> #### [Hittable](PPMs/hittable.ppm):
> ---
> - `hittable.h`
> - `hittable_list.h`
> - `rtweekend.h`
> - `sphere.h`
> - `hittable.cpp` \
> [![Hittable](PPMs/hittable.png "Hittable")](PPMs/hittable.ppm)

> #### [Camera](PPMs/camera.ppm):
> ---
> Same picture but form the 'view' of the `Camera()`
> - `camera.h`
> - `camera.cpp` \
> [![Intervals](PPMs/camera.png "Camera")](PPMs/camera.ppm)

> #### [Square Anti-Aliasing](PPMs/square_aa.ppm):
> ---
> - `interval.h`
> - `square_aa.cpp`: Implement AA \
> [![Square Anti Aliasing](PPMs/square_aa.png "Square Anti-Aliasing")](PPMs/square_aa.ppm)

> #### [Diffuse Material](PPMs/diffuse_1.ppm):
> ---
> - `camera.h`: 
>   - apply Lambertian Diffuse to `ray_color()`
>   - implement `max_depth` to prevent Stack Overflow
> - `vec3.h`: 
>   - Implemented random Vec3
> - `diffuse_1.cpp`
> 
> [![Diffuse Material](PPMs/diffuse_1.png "Diffuse Material")](PPMs/diffuse_1.ppm)

> #### [Gamma Correction](PPMs/gamma_1.ppm):
> ---
> - `color.h`:
>   - Convert to gamma-space `linear_to_gamma()`
> - `gamma_1.cpp`
> 
> [![Gamma Correction](PPMs/gamma_1.png "Gamma Correction")](PPMs/gamma_1.ppm)

---

