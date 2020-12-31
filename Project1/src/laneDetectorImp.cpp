#include <string>
#include <vector>
#include "opencv2/opencv.hpp"
#include <opencv2/imgproc.hpp>
#include "laneDetectorImp.h"

laneDetectorImp::laneDetectorImp(std::string path) {

    _cap.open(path);

    if (!_cap.isOpened())
        throw std::runtime_error("Problem openning the video!");

}

laneDetectorImp::~laneDetectorImp() {

    _cap.release();

}

void laneDetectorImp::deNoise(cv::Mat& in, cv::Mat& out) {

    cv::GaussianBlur(in, out, cv::Size(3, 3), 0, 0);

}

void laneDetectorImp::edgeDetector(cv::Mat& in, cv::Mat& out) {
  
    cv::Mat kernel;
    cv::Point anchor;

    cv::cvtColor(in, out, cv::COLOR_RGB2GRAY);

    cv::threshold(out, out, 140, 255, cv::THRESH_BINARY);

    anchor = cv::Point(-1, -1);
    kernel = cv::Mat(1, 3, CV_32F);
    kernel.at<float>(0, 0) = -1;
    kernel.at<float>(0, 1) = 0;
    kernel.at<float>(0, 2) = 1;

    cv::filter2D(out, out, -1, kernel, anchor, 0, cv::BORDER_DEFAULT);

}

void laneDetectorImp::mask(cv::Mat& in, cv::Mat& out) {
   
    cv::Mat mask = cv::Mat::zeros(in.size(), in.type());
    cv::Point pts[4] = {
        cv::Point(150, 720),
        cv::Point(530, 500),
        cv::Point(700, 500),
        cv::Point(1100, 720)
    };

    cv::fillConvexPoly(mask, pts, 4, cv::Scalar(255, 0, 0));

    cv::bitwise_and(in, mask, out);

}

void laneDetectorImp::houghLines(cv::Mat& in, std::vector<cv::Vec4i>& lines) {

    HoughLinesP(in, lines, 1, CV_PI / 180, 20, 20, 30);

}

void laneDetectorImp::readFrame(cv::Mat& frame) {

    if (!_cap.read(frame))
        throw std::runtime_error("Problem reading a frame!");

}

void laneDetectorImp::plot(std::vector<cv::Vec4i>& lines, cv::Mat& frame) {

    for (size_t i = 0; i < lines.size(); i++)
    {
        cv::Vec4i l = lines[i];
        cv::line(frame, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
    }

    cv::imshow("Result Image", frame);

}

