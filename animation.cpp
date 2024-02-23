#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <cmath>

void drawCurvedLine(cv::Mat& image, cv::Point start, cv::Point end, cv::Scalar lineColor, double steering_angle, int lineThickness) {
    // ... (unchanged)
    double length = cv::norm(end - start);

    for (int i = 0; i < length; ++i) {
        double t = static_cast<double>(i) / length;
        int x = static_cast<int>(start.x + t * (end.x - start.x));
        int y = static_cast<int>(start.y + t * (end.y - start.y) + 50 * sin(t * CV_PI) * steering_angle / 30.0);

        for (int j = -lineThickness / 2; j <= lineThickness / 2; ++j) {
            for (int k = -lineThickness / 2; k <= lineThickness / 2; ++k) {
                int newX = x + j;
                int newY = y + k;
                if (newX >= 0 && newX < image.cols && newY >= 0 && newY < image.rows) {
                    image.at<cv::Vec3b>(newY, newX) = cv::Vec3b(lineColor[0], lineColor[1], lineColor[2]);
                }
            }
        }
    }
}

int main() {
    // Load the camera image (replace with your image file path)
    cv::Mat image = cv::imread("testimage.png");

    // Check if the image was loaded successfully
    if (image.empty()) {
        std::cerr << "Error: Unable to load the image 'camera_image.jpg'" << std::endl;
        return -1;
    }

    // Define the specified lines as a vector of tuples containing start and end points and line colors.
    std::vector<std::tuple<cv::Point, cv::Point, cv::Scalar>> specified_lines = {
        {cv::Point(40, 1050), cv::Point(760, 240), cv::Scalar(0, 0, 255)},        // Red
    };

  // Define the specified lines as a vector of tuples containing start and end points and line colors.
    std::vector<std::tuple<cv::Point, cv::Point, cv::Scalar>> specified_lines1 = {
        {cv::Point(1880, 1050), cv::Point(1200, 240), cv::Scalar(0, 0, 255)},    // Red
    };


    // Specify the output video file
    cv::VideoWriter video("steering_animation1.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'),5, image.size());

    // Iterate through steering angles and create frames
    for (int steering_angle = -60; steering_angle <= 60; steering_angle += 5) {
        // Clear the image for a fresh set of lines
        image = cv::imread("testimage.png");
         cv :: Point l1 ,l2;
        // Calculate the guideline position based on the user's input
        int center_x = image.cols / 2;

        // Update the positions of the specified lines
        //std::vector<std::tuple<cv::Point, cv::Point, cv::Scalar>> updated_lines1;
         std::vector<std::tuple<cv::Point, cv::Point, cv::Scalar>> updated_lines;
        std::vector<std::tuple<cv::Point, cv::Point, cv::Scalar>> updated_lines1;
        for (const auto& line : specified_lines) {
            cv::Point start = std::get<0>(line);
            
           cv::Point end;

        if (&line == &*std::begin(specified_lines)) {//left line strats decreasing...

             /*  positive values   */
              if(steering_angle == 0)
            {
            //end = cv::Point(720,270);
             end = cv::Point(760,240);
            }
            if(steering_angle == 5)
            {
            //end = cv::Point(720,270);
             end = cv::Point(670,270);
            }
            if(steering_angle == 10)
            {
            end = cv::Point(620,300);
            }
             if(steering_angle == 15)
            {
            end = cv::Point(570, 330);
            }
            if(steering_angle == 20)
            {
            end = cv::Point(520, 360);
            }
             if(steering_angle == 25)
            {
            end = cv::Point(470, 390);
            }
            if(steering_angle == 30)
            {
            end = cv::Point(420, 420);
            }

            //left line

            if(steering_angle == 35)
            {
              end = cv::Point(370,450);
            }
            if(steering_angle == 40)
            {
              end = cv::Point(320,480);
            }
            if(steering_angle == 45)
            {
              end = cv::Point(270,510);
            }
            if(steering_angle == 50)
            {
              end = cv::Point(220,540);
            }
            if(steering_angle == 55)
            {
              end = cv::Point(170,570);
            }
            if(steering_angle == 60)
            {
              end = cv::Point(120,600); //left line
            }

            /**************negetive values***************/
            if(steering_angle == -5)
            {
            end = cv::Point(780,240);
            }
            if(steering_angle == -10)
            {
            end = cv::Point(820,240);
            }
            if(steering_angle == -15)
            {
              end = cv::Point(860, 240);
            }
            if(steering_angle == -20)
            {
            end = cv::Point(900, 240);
            }
            if(steering_angle == -25)
            {
            end = cv::Point(940, 240);
            }
            if(steering_angle == -30)
            {
              end = cv::Point(980,240);
            }
            //left line 
            if(steering_angle == -35)
            {
              end = cv::Point(1020,240);
            }
            if(steering_angle == -40)
            {
              end = cv::Point(1060,240);
            }
            if(steering_angle == -45)
            {
              end = cv::Point(1100,240);
            }
            if(steering_angle == -50)
            {
              end = cv::Point(1140,240);
            }
            if(steering_angle == -55)
            {
              end = cv::Point(1180,240);
            }
            if(steering_angle == -60)
            {
              end = cv::Point(1220,240); //left line
            }
            
        } else {
          	 end = std::get<1>(line);
           // end = cv::Point(1350, 230);
        }
        l1=end;
            //cv::Point end = std::get<1>(line);
            cv::Scalar color = std::get<2>(line);
            int start_x = center_x + (start.x - center_x);
            int end_x = center_x + (end.x - center_x);
            updated_lines.push_back(std::make_tuple(cv::Point(start_x, start.y), cv::Point(end_x, end.y), color));
        }
     for (const auto& line : specified_lines1) {
            cv::Point start = std::get<0>(line);
           // cv::Point end = std::get<1>(line);
            cv::Point end;

        if (&line == &*std::begin(specified_lines1)) { //right line
            
            /*  positive values   */
             if(steering_angle == 0)
            {
            end = cv::Point(1200,240);
            }
            if(steering_angle == 5)
            {
            end = cv::Point(1140,240);
            }
            if(steering_angle == 10)
            {
            end = cv::Point(1100,240);
            }
            if(steering_angle == 15)
            {
            end = cv::Point(1060, 240);
            }
            if(steering_angle == 20)
            {
            end = cv::Point(1020, 240);
            }
             if(steering_angle == 25)
            {
            end = cv::Point(980, 240);
            }
             if(steering_angle == 30)
            {
            end = cv::Point(940, 240);
            }

            //right line

            if(steering_angle == 35)
            {
              end = cv::Point(900,240);
            }
            if(steering_angle == 40)
            {
              end = cv::Point(860,240);
            }
            if(steering_angle == 45)
            {
              end = cv::Point(820,240);
            }
            if(steering_angle == 50)
            {
              end = cv::Point(780,240);
            }
            if(steering_angle == 55)
            {
              end = cv::Point(740,240);
            }
            if(steering_angle == 60)
            {
              end = cv::Point(700,240); //right line
            }

            /**************negetive values***************/
            if(steering_angle == -5)
            {
            end = cv::Point(1250,260);
            }
            if(steering_angle == -10)
            {
            end = cv::Point(1300,290);
            }
            if(steering_angle == -15)
            {
            end = cv::Point(1350, 320);
            }
            if(steering_angle == -20)
            {
            end = cv::Point(1400, 350);
            }
             if(steering_angle == -25)
            {
            end = cv::Point(1450, 380);
            }
            if(steering_angle == -30)
            {
            end = cv::Point(1500, 410);
            }

            //right line

            if(steering_angle == -35)
            {
              end = cv::Point(1550,440);
            }
            if(steering_angle == -40)
            {
              end = cv::Point(1600,470);
            }
            if(steering_angle == -45)
            {
              end = cv::Point(1650,500);
            }
            if(steering_angle == -50)
            {
              end = cv::Point(1700,530);
            }
            if(steering_angle == -55)
            {
              end = cv::Point(1750,560);
            }
            if(steering_angle == -60)
            {
              end = cv::Point(1800,590); //right line
            }
            //end = cv::Point(1050, 240);
        } else {
          	 end = std::get<1>(line);
           // end = cv::Point(1350, 230);
        }
         l2 = end;
            cv::Scalar color = std::get<2>(line);

            int start_x = center_x + (start.x - center_x);
            int end_x = center_x + (end.x - center_x);

            updated_lines1.push_back(std::make_tuple(cv::Point(start_x, start.y), cv::Point(end_x, end.y), color));
        }
        // Draw the specified lines on the image with curvature
        for (const auto& line : updated_lines) {
            drawCurvedLine(image, std::get<0>(line), std::get<1>(line), std::get<2>(line), steering_angle, 2);
        }
         for (const auto& line : updated_lines1) {
            drawCurvedLine(image, std::get<0>(line), std::get<1>(line), std::get<2>(line), -(steering_angle), 2);
        }
        cv::line(image,l1,l2,cv::Scalar(0,0,255), 2);
        cv::line(image,cv::Point(616, 402), cv::Point(760, 240), cv::Scalar(0, 255, 0), 2);    
        cv::line(image,cv::Point(364, 685), cv::Point(616, 402), cv::Scalar(0, 255, 255), 2);
        cv::line(image,cv::Point(40, 1050), cv::Point(364, 685), cv::Scalar(0, 0, 255), 2);
        cv::line(image,cv::Point(1336, 402), cv::Point(1200, 240), cv::Scalar(0, 255, 0), 2);
        cv::line(image,cv::Point(1574, 685), cv::Point(1336, 402), cv::Scalar(0, 255, 255), 2);
        cv::line(image,cv::Point(1880, 1050), cv::Point(1574, 685), cv::Scalar(0, 0, 255), 2);
        cv::line(image,cv::Point(760, 240), cv::Point(1200, 240), cv::Scalar(0, 255, 0), 2);
    
        // Draw the specified lines on the image with curvature
       

        // Draw the angle text on the image
 for (int x = 10; x < image.cols; x += 10) {
        cv::line(image, cv::Point(x, 0), cv::Point(x, image.rows), cv::Scalar(0, 0, 0), 1);  // Black vertical line
        if (x % 50 == 0) {
            cv::putText(image, std::to_string(x), cv::Point(x, 20), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 2);
        }
    }

    for (int y = 10; y < image.rows; y += 10) {
        cv::line(image, cv::Point(0, y), cv::Point(image.cols, y), cv::Scalar(0, 0, 0), 1);  // Black horizontal line
        if (y % 50 == 0) {
            cv::putText(image, std::to_string(y), cv::Point(5, y + 5), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 2);
        }
    }
        // Write the frame to the video
        video.write(image);

        // Display the image with the updated lines
        cv::imshow("Backup Camera", image);
        cv::waitKey(500);  // Adjust the delay between frames (in milliseconds)
    }

    // Release the video writer
    video.release();

    return 0;
}

