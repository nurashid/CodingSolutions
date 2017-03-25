int visiblePoints(std::vector<std::vector<int>> points) {
    map<double, int> pointmap;
    
    for (auto point : points)
        pointmap[atan2(point[1],point[0])]++;
    
    auto it = pointmap.begin();
    int mp = it->second, cp = it->second; // mp: max points, cp: current max points
    auto bit = it++;
    while (it != pointmap.end()) {
        if ((it->first - bit->first) <= (M_PI_4 + numeric_limits<double>::epsilon())) {
            cp += it->second;
            mp = max(mp, cp);
            it++;
        } else {
            cp -= bit->second;
            bit++;
        }
    }
    
    return mp;
}
