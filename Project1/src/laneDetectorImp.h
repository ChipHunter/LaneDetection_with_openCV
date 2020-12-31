#pragma once
#include <opencv2/highgui/highgui.hpp>
#include<iostream>
#include <string>
#include <vector>
#include "opencv2/opencv.hpp"

class laneDetectorImp {
public:
	laneDetectorImp(std::string path);
	~laneDetectorImp();

	void deNoise(cv::Mat& in, cv::Mat& out);
	void edgeDetector(cv::Mat& in, cv::Mat& out);
	void mask(cv::Mat& in, cv::Mat& out);  
	void houghLines(cv::Mat& in, std::vector<cv::Vec4i>& lines);
	void readFrame(cv::Mat& frame);
	void plot(std::vector<cv::Vec4i>& lines, cv::Mat& frame);

private:
	cv::VideoCapture _cap;
};