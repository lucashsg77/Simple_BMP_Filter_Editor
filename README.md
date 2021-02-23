# Quick breakdown

I submited some BMP's already but if you want to try your own, Windows's paint can save/convert images from any format to a 24-bit BMP you just need to open it there and click save, then choose to save as a 24-bit BMP.
So in case you want to use this in QT I will leave the .pro file here, but in case you want to use the BMP parser and it's filters anywhere else to do so is very simple.
1. You will need to use the image(.h and .cpp files) and the bitmap classes(.h and .cpp files) to get the BMP parser to work.
2. Next thing is to get the filter class and figure out what filters you want to use.
3. If the filters you want to use are either one of the following: High_pass or Low_pass, you'll need to take the convolution class(.h and .cpp files) with them.
4. Otherwise you just need to take the filter class and the filter you choose.
For example, if you were to use an grayscale filter on your project go and take the grayscale class together with the bitmap, image and filter classes, now if you were to use any of the blurs in the Low_pass class you would need to take the following classes: bitmap, image, filter, low_pass and convolution.

To use any of the filters first you need to read the BMP, then create an object of the filter class you chose and then call the function to actually apply the filter, after that attribute the filtered pixel data to a vector<uint8_t>, the way to use most filters is like the following example:

```
Bitmap bmp;
bmp.read("your_BMP_img.bmp");
vector<uint8_t> BMP_original_pixels = bmp.img_pixel_data();
Grayscale grayscale(BMP_original_pixels);
grayscale.grayscale_filter();
vector<uint8_t> BMP_filtered_pixels = grayscale.filtered_pixel_data();
```

# Usage

The Bitmap class is the foundation of this program it has basically only two functions which are the I/O ones and the constructor which uses the read function, use them as indicated bellow:
| Function | Parameters | Usage |
| --- | --- | --- |
| Read | `const char* filename`  | `bmp.read("your_BMP_img.bmp")`
| Write | `const char* filename, vector<uint8_t> data` | `bmp.write("filtered_BMP.bmp")` |
| Constructor | `const char* filename` | `Bitmap bmp("your_BMP_img.bmp")` |

After reading the bmp your Bitmap object will have all of the bmp header infos.(height, width, size, etc.).

All filter classes are to be declared with a capital first letter, like so: Grayscale, Brightness, Low_pass, High_pass...

To be able to create a new object the constructors will need some parameters:
| Filter | Parameters | Usage |
| --- | --- | --- |
| **Mirror filters, Low_pass or High_pass** | `int img_height, int img width, vector<uint8_t> your_BMP_bits`  | `Chosen_filter chosen_filter_object(img_height, img width, your_BMP_bits)`
| **Rest of the filters** | `vector<uint8_t> your_BMP_bits` | `Chosen_filter chosen_filter_object(vector<uint8_t> your_BMP_bits)` |

After creating your filter object and applying the filter you can access it's filtered data easily with the ```filter_object.filtered_pixel_data()``` function.

Most filters will be applied if you use ```filter_object.filter_class_filter(class_parameters)``` but there are some exceptions, they are the following: Low_pass filters, High_pass, HSV_color_model_operations and Histogram. In order to use them please look at the examples below:

**1. Low_pass**
| Filter | Parameters | Usage |
| --- | --- | --- |
| Smoothing | no parameter  | `low_pass_object.smoothing()` |
| Median | `int mask_radius` | `low_pass_object.median(mask_radius)` |
| Box_blur | `int blur_radius` | `low_pass_object.box_blur(blur_radius)` |
| Gaussian_blur | `int blur_radius` | `low_pass_object.gaussian_blur(blur_radius)` |

**2.High_pass**
| Filter | Parameters | Usage |
| --- | --- | --- |
| High_pass | `int mask_radius` | `high_pass_object.high_pass(mask_radius)` |

**3.HSV_color_model_operations**
| Filter | Parameters | Usage |
| --- | --- | --- |
| BrightnessHSV | `double increase_percentage` | `hsv_model_object.brightnessHSV(increase_percentage)` |
| SaturationHSV | `double increase_percentage` | `hsv_model_object.saturationHSV(increase_percentage)` |

**4.Histogram**
| Filter | Parameters | Usage |
| --- | --- | --- |
| Eq_histogram | no parameter | `histogram_object.eq_histogram()` |

**5.For the rest of the filters refer to the table below:**
| Filter | Parameters | Usage|
| --- | --- |---|
| Brightness | `uint8_t bright` |`brightness.brightness_filter(bright)`|
| Contrast | `double contrast` |`contrast.contrast_filter(contrast)`|
| Grayscale | no parameter |`grayscale.grayscale_filter()`|
| Horizontal_mirror | no parameter |`horizontal_mirror.horizontal_mirror_filter()`|
| HV_mirror | no parameter |`hv_mirror.hv_mirror_filter();`|
| Vertical_mirror | no parameter |`vertical_mirror.vertical_mirror_filter()`|
| Negative | no parameter |`negative.negative_filter()`|
| Rotate | `double degrees`|`rotate.rotate_filter(degrees)`|
| SaturationRGB | `string selected_channel, uint8_t saturation_value`|` saturationRGB.saturationRGB (selected_channel, saturation_value)`|
| SelectRGB | `string selected_channel`|`selectRGB.selectRGB_filter (channel)` |
| Sepia | no parameter |`sepia.sepia_filter()`|
| Threshold  | `int threshold_value` |`threshold.threshold_filter(threshold_value)`|

If there are any doubts on how to use it I think that a quick look at the mainwindow.cpp will enlighten you on how to use the filters.

## Other considerations
With the HSV besides the brightness and saturation you can change the HUE too, all you need to do is a function to do so given that the function to transform BGR to HSV is already done and if you only need the histogram as well you can also take it separately and use some other library to plot a graph, if needed in QT you could use the script engine built in and use matplotlib in python to do so.

There are ways to make this code better and faster, one thing that most image libraries have that I did not implement is a FFT that can make the convolution part of the process speed up drastically, as well as, the coding itself could be better but this project was an experiment to me and I'll be updating it from time to time with some refactors, soon I will have it working on 32 bits BMP as well as other RAW image formats, so feel free to improve the code if you want to!
