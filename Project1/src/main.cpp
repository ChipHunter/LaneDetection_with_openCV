#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "laneDetector.h"
#include <memory>


int main() {

    cv::Mat frame, img_denoise, img_edges, img_mask;
    std::vector<cv::Vec4i> lines;
    
    try {
        std::unique_ptr<laneDetector> laneDetector = std::make_unique<laneDetectorAlgo1>("Res/theVideo.mp4");

        while (true) {

            laneDetector->readFrame(frame);

            laneDetector->deNoise(frame, img_denoise);

            laneDetector->edgeDetector(img_denoise, img_edges);

            laneDetector->mask(img_edges, img_mask);

            laneDetector->houghLines(img_mask, lines);


            if (!lines.empty()) {

                laneDetector->plot(lines, frame);
               
            }

            cv::waitKey(25);

        }
    } catch(std::exception& e) {
    
        std::cout << "some exception: " << e.what() << std::endl;

    } catch (...) {

        std::cout << "other exception: " << std::endl;

    }

    return 0;
}