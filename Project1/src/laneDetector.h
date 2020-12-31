#pragma once
#include "opencv2/opencv.hpp"
#include "laneDetectorImp.h"
#include <string>

class laneDetector {
public:
	laneDetector(std::string path);

	virtual void deNoise(cv::Mat& in, cv::Mat& out) = 0;
	virtual void edgeDetector(cv::Mat& in, cv::Mat& out) = 0;
	virtual void mask(cv::Mat& in, cv::Mat& out) = 0;
	virtual void houghLines(cv::Mat& in, std::vector<cv::Vec4i>& lines) = 0;
	virtual void readFrame(cv::Mat& frame) = 0;
	virtual void plot(std::vector<cv::Vec4i>& lines, cv::Mat& frame) = 0;

protected:
	laneDetectorImp _laneDetectorImp;
};


class laneDetectorAlgo1 : public laneDetector {
public:
	laneDetectorAlgo1(std::string path);

	void deNoise(cv::Mat& in, cv::Mat& out) final override;
	void edgeDetector(cv::Mat& in, cv::Mat& out) final override;
	void mask(cv::Mat& in, cv::Mat& out) final override;
	void houghLines(cv::Mat& in, std::vector<cv::Vec4i>& lines) final override;
	void readFrame(cv::Mat& frame) final override;
	void plot(std::vector<cv::Vec4i>& lines, cv::Mat& frame) final override;
};