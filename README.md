# OpenCV Projects – C++ Face & License Plate Detection

This repository includes three C++ computer vision projects developed with OpenCV. Each project demonstrates real-time or static object detection using pre-trained Haar Cascade classifiers.

## Projects Included

### Face Detection from Image
- Loads a static image
- Uses Haar Cascade for frontal face detection
- Draws bounding boxes around detected faces

### License Plate Detection from Image
- Loads a car image containing a visible license plate
- Uses `haarcascade_russian_plate_number.xml` for plate detection
- Highlights plates using rectangles

### License Plate Detection from Video
- Opens a video feed (camera or `.mp4`)
- Processes each frame in real-time
- Detects and highlights license plates
- Displays cropped plate region in a separate window

## Technologies Used

- C++
- OpenCV (imgproc, highgui, objdetect)
- Haar Cascade Classifiers
- Visual Studio / g++ / CMake

