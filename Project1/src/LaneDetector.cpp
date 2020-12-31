#include "laneDetector.h"
#include <vector>
#include <stdexcept>

laneDetector::laneDetector(std::string path) : _laneDetectorImp(path) {}

laneDetectorAlgo1::laneDetectorAlgo1(std::string path) : laneDetector(path) {};

void laneDetectorAlgo1::deNoise(cv::Mat& in, cv::Mat& out) {

    _laneDetectorImp.deNoise(in, out);

}

void laneDetectorAlgo1::mask(cv::Mat& in, cv::Mat& out) {

    _laneDetectorImp.mask(in, out);
}


void laneDetectorAlgo1::houghLines(cv::Mat& in, std::vector<cv::Vec4i>& lines) {

        _laneDetectorImp.houghLines(in, lines);

}

void laneDetectorAlgo1::readFrame(cv::Mat& frame) {

    _laneDetectorImp.readFrame(frame);

}

void laneDetectorAlgo1::plot(std::vector<cv::Vec4i>& lines, cv::Mat& frame) {

    _laneDetectorImp.plot(lines, frame);

}

void laneDetectorAlgo1::edgeDetector(cv::Mat& in, cv::Mat& out) {

    _laneDetectorImp.edgeDetector(in, out);
}
