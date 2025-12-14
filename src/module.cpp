// SPDX-FileCopyrightText: (c) 2023 Silverlan <opensource@pragma-engine.com>
// SPDX-License-Identifier: MIT

#include <opencv2/opencv.hpp>

import pragma.shared;

static int to_cv_format(pragma::image::Format format)
{
	switch(format) {
	case pragma::image::Format::R8:
		return CV_8UC1;
	case pragma::image::Format::RG8:
		return CV_8UC2;
	case pragma::image::Format::RGB8:
		return CV_8UC3;
	case pragma::image::Format::RGBA8:
		return CV_8UC4;

	case pragma::image::Format::R16:
		return CV_16UC1;
	case pragma::image::Format::RG16:
		return CV_16UC2;
	case pragma::image::Format::RGB16:
		return CV_16UC3;
	case pragma::image::Format::RGBA16:
		return CV_16UC4;

	case pragma::image::Format::R32:
		return CV_32SC1;
	case pragma::image::Format::RG32:
		return CV_32SC2;
	case pragma::image::Format::RGB32:
		return CV_32SC3;
	case pragma::image::Format::RGBA32:
		return CV_32SC4;
	}
	throw std::runtime_error {"Unsupported image format " + std::to_string(pragma::math::to_integral(format))};
}

static cv::Mat create_opencv_mat(const pragma::image::ImageBuffer &imgBuf) { return cv::Mat {static_cast<int32_t>(imgBuf.GetHeight()), static_cast<int32_t>(imgBuf.GetWidth()), to_cv_format(imgBuf.GetFormat()), const_cast<void *>(imgBuf.GetData())}; }

extern "C" {

PR_EXPORT void pragma_initialize_lua(Lua::Interface &lua)
{
	auto &libDemo = lua.RegisterLibrary("opencv");
	libDemo[(luabind::def(
	           "copy",
	           +[](const pragma::image::ImageBuffer &psrc, pragma::image::ImageBuffer &dst, uint32_t x, uint32_t y, uint32_t w, uint32_t h) {
		           auto &src = const_cast<pragma::image::ImageBuffer &>(psrc);
		           dst.ClampBounds(x, y, w, h);
		           auto srcMat = create_opencv_mat(src);
		           auto dstMat = create_opencv_mat(dst);

		           cv::Rect srcRoi {0, 0, static_cast<int32_t>(w), static_cast<int32_t>(h)};
		           cv::Rect dstRoi {static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(w), static_cast<int32_t>(h)};
		           srcMat(srcRoi).copyTo(dstMat(dstRoi));
	           }),
	  luabind::def(
	    "resize",
	    +[](const pragma::image::ImageBuffer &img, uint32_t newWidth, uint32_t newHeight) {
		    auto imgOut = pragma::image::ImageBuffer::Create(newWidth, newHeight, img.GetFormat());
		    auto matIn = create_opencv_mat(img);
		    auto matOut = create_opencv_mat(*imgOut);
		    cv::Size size {static_cast<int32_t>(newWidth), static_cast<int32_t>(newHeight)};
		    cv::resize(matIn, matOut, size, 0, 0, cv::INTER_AREA);
		    return imgOut;
	    }),
	  luabind::def(
	    "save", +[](const pragma::image::ImageBuffer &img, const std::string &filePath) {
		    auto cpy = img.Copy(pragma::image::ImageBuffer::ToLDRFormat(img.GetFormat()));
		    auto matIn = create_opencv_mat(*cpy);
		    std::vector<cv::Mat> channels;
		    cv::split(matIn, channels);
		    std::swap(channels[0], channels[2]);
		    cv::merge(channels, matIn);
		    return cv::imwrite(filePath, matIn);
	    }))];
}
};
