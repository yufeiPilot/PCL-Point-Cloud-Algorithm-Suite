//
// Created by yufei on 24-7-17.
//

#ifndef PCL_POINT_CLOUD_ALGORITHM_SUITE_PASS_THROUGH_FILTER_H
#define PCL_POINT_CLOUD_ALGORITHM_SUITE_PASS_THROUGH_FILTER_H
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/filters/passthrough.h>

class PassThroughFilter {
    public:
        PassThroughFilter();
        void setInputCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud);
        void setFilterLimits(float minLimit, float maxLimit);
        void setFilterFieldName(const std::string &field_name);
        pcl::PointCloud<pcl::PointXYZ>::Ptr filter();

    private:
        pcl::PassThrough<pcl::PointXYZ> pass_;
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_;
};
#endif //PCL_POINT_CLOUD_ALGORITHM_SUITE_PASS_THROUGH_FILTER_H
