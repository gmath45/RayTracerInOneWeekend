#ifndef CAMERA_H
#define CAMERA_H

#include "hittable.h"

class camera {
    public:
        /* Public Camera Parameters */
        double  aspect_ratio      = 1.0;
        int     image_width       = 100;
        int     samples_per_pixel = 10;

        void render(const hittable& world) {
            initialize();

            std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

            for (int j = 0; j < image_height; j++) {
                std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
                for (int i = 0; i < image_width; i++) {
                    color pixel_color(0,0,0);
                    for (int sample = 0; sample < samples_per_pixel; sample++) {
                        ray r = get_ray(i, j);
                        pixel_color += ray_color(r, world);
                    }
                    write_color(std::cout, pixel_samples_scale * pixel_color);
                }
            }

            std::clog << "\rDone.                 \n";
        }

    private:
        /* Private Camera Parameters */
        int     image_height;
        double  pixel_samples_scale;
        Point3  center;
        Point3  pixel00_loc;
        Vec3    pixel_delta_u;
        Vec3    pixel_delta_v;

        void initialize() {
            image_height = int(image_width / aspect_ratio);
            image_height = (image_height < 1) ? 1 : image_height;

            pixel_samples_scale = 1.0 / samples_per_pixel;

            center = Point3(0,0,0);

            // Determine viewport specs
            auto focal_length = 1.0;
            auto viewport_height = 2.0;
            auto viewport_width = viewport_height * (double(image_width)/image_height);

            // Calculate Vectors along Viewport edges
            auto viewport_u = Vec3(viewport_width, 0, 0);
            auto viewport_v = Vec3(0, -viewport_height, 0);

            // Calculate Pixel-to-Pixel Vectors
            pixel_delta_u = viewport_u / image_width;
            pixel_delta_v = viewport_v / image_height;

            // Calculate Origin(Upper Left)
            auto viewport_upper_left = center - Vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
            pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
        }

        ray get_ray(int i, int j) const {
            // Construct Camera ray at Random points, taking samples
            auto offset = sample_square();
            auto pixel_sample = pixel00_loc +
                                ((i + offset.x()) * pixel_delta_u) +
                                ((j + offset.y()) * pixel_delta_v);
            
            auto ray_origin = center;
            auto ray_direction = pixel_sample - ray_origin;

            return ray(ray_origin, ray_direction);
        }

        Vec3 sample_square() const {
            // Return Vector @ points [-0.5,-0.5]->[0.5,0.5]
            return Vec3(random_double() - 0.5, random_double() - 0.5, 0);
        }

        color ray_color(const ray& r, const hittable& world) const {
            hit_record rec;

            if (world.hit(r, interval(0, INF), rec)) {
                return 0.5 * (rec.normal + color(1,1,1));
            }

            Vec3 unit_direction = UV(r.direction());
            auto a = 0.5 * (unit_direction.y() + 1.0);
            return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
        }

};

#endif