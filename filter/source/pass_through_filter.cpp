//
// Created by yufei on 24-7-17.
//
#include "PassThroughFilter.h"

PassThroughFilter::PassThroughFilter() : cloud_(new pcl::PointCloud<pcl::PointXYZ>) {}

void PassThroughFilter::setInputCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud) {
    cloud_ = cloud;
}

void PassThroughFilter::setFilterLimits(float minLimit, float maxLimit) {
    pass_.setFilterLimits(minLimit, maxLimit);
}

void PassThroughFilter::setFilterFieldName(const std::string &field_name) {
    pass_.setFilterFieldName(field_name);
}

pcl::PointCloud<pcl::PointXYZ>::Ptr PassThroughFilter::filter() {
    pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pass_.setInputCloud(cloud_);
    pass_.filter(*filtered_cloud);
    return filtered_cloud;
}