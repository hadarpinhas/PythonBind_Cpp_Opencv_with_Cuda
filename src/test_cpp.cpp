#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>  // Needed for returning a NumPy array
#include <opencv2/opencv.hpp>
#include <iostream>

// Function to load two images, subtract them, and return the mask (difference)
pybind11::array_t<unsigned char> run_main(const std::string& img_path1, const std::string& img_path2) {
    // Load the first image
    cv::Mat img1 = cv::imread(img_path1, cv::IMREAD_GRAYSCALE);
    if (img1.empty()) {
        throw std::runtime_error("Error: Could not open or find the image at " + img_path1);
    }

    // Load the second image
    cv::Mat img2 = cv::imread(img_path2, cv::IMREAD_GRAYSCALE);
    if (img2.empty()) {
        throw std::runtime_error("Error: Could not open or find the image at " + img_path2);
    }

    // Ensure both images are the same size
    if (img1.size() != img2.size()) {
        throw std::runtime_error("Error: Images must be the same size.");
    }

    // Subtract the images to create a mask
    cv::Mat mask;
    cv::absdiff(img1, img2, mask);

    // Convert the mask to a NumPy array and return it to Python
    pybind11::array_t<unsigned char> mask_array(
        { mask.rows, mask.cols },  // Shape of the array
        mask.data);  // Pointer to the data in the mask Mat

    return mask_array;
}

// Define the Python module using pybind11
PYBIND11_MODULE(cpp_example, m) {
    m.doc() = "A Python module that processes two images and returns a mask"; // Optional module docstring

    // Expose the run_vmd function to Python
    m.def("run_main", &run_main, "Run the main function to load, subtract two images, and return the mask",
        pybind11::arg("img_path1"), pybind11::arg("img_path2"));
}




// Main function when building as an executable
//#ifdef BUILD_AS_EXE
//int main() {
//    return run_main();
//}
//#endif

/////////////////////   pybind11

//#ifndef BUILD_AS_EXE  // Only include this if not building as an executable
