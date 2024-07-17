//
// Created by yufei on 24-7-17.
//
#include <iostream>
#include <pcl/io/pcd_io.h>
#include "PassThroughFilter.h"

int main() {
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>());
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered;

    if (pcl::io::loadPCDFile<pcl::PointXYZ>("inputCloud.pcd", *cloud) == -1) {
        PCL_ERROR("Couldn't read file inputCloud.pcd \n");
        return -1;
    }

    PassThroughFilter filter;
    filter.setInputCloud(cloud);
    filter.setFilterFieldName("z");
    filter.setFilterLimits(0.0, 1.0);
    cloud_filtered = filter.filter();

    pcl::io::savePCDFile("filteredCloud.pcd", *cloud_filtered);

    std::cout << "Cloud after filtering: " << std::endl;
    for (const auto& point : *cloud_filtered)
        std::cout << "    " << point.x << " "
                  << point.y << " "
                  << point.z << std::endl;

    return 0;
}
