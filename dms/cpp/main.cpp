#include <opencv2/core.hpp>
// #include <opencv2/highgui.hpp>
#include <iostream>

cv::Mat padding(cv::Mat image) {
    cv::Mat padded;
    int h = image.rows;
    int w = image.cols;
    printf("h: %d, w: %d\n", h, w);
    int target_dim = cv::max(w, h);
    printf("target_dim: %d\n", target_dim);
    int pad_top = (target_dim - h) / 2;
    int pad_bottom = (target_dim - h + 1) / 2;
    int pad_left = (target_dim - w) / 2;
    int pad_right = (target_dim - w + 1) / 2;
    cv::copyMakeBorder(image, padded, pad_top, pad_bottom,
                        pad_left, pad_right, cv::BORDER_CONSTANT, 0);
    cv::flip(padded, padded, 1);
    // std::cout << "padded_size: " << padded.size() << std::endl;
    printf("padded_size: [%d x %d]\n", padded.rows, padded.cols);
    return padded;
}

void dump(cv::Mat image) {
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            // std::cout << image.at<cv::Vec3b>(i, j) << " ";
            printf("[%u, %u, %u] ",
                static_cast<unsigned int>(image.at<cv::Vec3b>(i, j)[0]),
                static_cast<unsigned int>(image.at<cv::Vec3b>(i, j)[1]),
                static_cast<unsigned int>(image.at<cv::Vec3b>(i, j)[2])
                );
        }
        // std::cout << std::endl;
        printf("\n");
    }
}

int main() {
    printf("Built with OpenCV %s\n\n", CV_VERSION);

    // cv::Mat image = cv::imread("/home/moke/code/ml14m22z/eiq-example/dms/grace_hopper.bmp");
    // if (image.empty()) {
    //     std::cerr << "Image not found" << std::endl;
    //     return 1;
    // }

    // cv::Mat image(606, 517, CV_8UC3, cv::Scalar(0, 0, 255));
    cv::Mat image(6, 5, CV_8UC3, cv::Scalar(0, 0, 255));

    cv::Mat padded = padding(image);

    dump(padded);
    
    // cv::imshow("Padded Image", padded);

    // cv::waitKey(0);

    return 0;
}
