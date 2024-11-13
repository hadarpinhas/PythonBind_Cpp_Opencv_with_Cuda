import os
import matplotlib.pyplot as plt

# Add paths for required DLLs
os.add_dll_directory(r"C:\Program Files\NVIDIA\CUDNN\v9.1\bin\11.8")  # For cuDNN DLLs
os.add_dll_directory(r"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.8\bin")  # For CUDA DLLs
os.add_dll_directory(r"C:\opencv\install\x64\vc16\bin")  # For OpenCV DLLs

# Import the custom module created from the .pyd file
from x64.Release import cpp_example

# Define the paths to the images
img_path1 = "img1.jpg"
img_path2 = "img2.jpg"

# Call the function that subtracts the images and returns the mask
mask = cpp_example.run_main(img_path1, img_path2)

# Display the mask using matplotlib
plt.imshow(mask, cmap='gray')
plt.title("Mask (Difference Between Images)")
plt.axis('off')
plt.show()
