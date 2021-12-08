//    {
//        // t = 0
//        Mat h = build(0);
//        vector<vector<ll>> equations(3);
//        for (int i = 0; i <= 2; ++i) {
//            equations[0].push_back((h^i)[0][0].Toll());
//            equations[1].push_back((h^i)[1][0].Toll());
//            equations[2].push_back((h^i)[1][2].Toll());
//        }
//        Mat c(equations);
//        //cout << c << '\n';
//        c.Eliminate();
//        cout << c << '\n';
//    }
//    {
//        //t = -4
//        Mat h = build(-4);
//        vector<vector<ll>> equations(4);
//        for (int i = 0; i <= 3; ++i) {
//            equations[0].push_back((h^i)[0][0].Toll());
//            equations[1].push_back((h^i)[1][0].Toll());
//            equations[2].push_back((h^i)[0][2].Toll());
//            equations[3].push_back((h^i)[2][2].Toll());
//        }
//        Mat c(equations);
//        //cout << c << '\n';
//        c.Eliminate();
//        cout << c << '\n';
//    }
//    {
//        //t = -3;
//        Mat h = build(-3);
//        vector<vector<ll>> equations(4);
//        for (int i = 0; i <= 3; ++i) {
//            equations[0].push_back((h^i)[0][0].Toll());
//            equations[1].push_back((h^i)[1][0].Toll());
//            equations[2].push_back((h^i)[0][2].Toll());
//            equations[3].push_back((h^i)[1][2].Toll());
//        }
//        Mat c(equations);
//        //cout << c << '\n';
//        c.Eliminate();
//        cout << c << '\n';
//
//    }
//auto build = [](int t) {
//    cout << "t = " << t << " :\n";
//    return vector<vector<ll>>{{3, 0, -4 * t},
//                              {-2, 3, -8 - 2 * t},
//                              {0, 0, 3 + t}
//    };
//};
//
//auto solver = [&](int t) {
//    Mat h = build(t);
//    vector<vector<ll>> equations(5);
//    for (int i = 0; i <= 3; ++i) {
//        equations[0].push_back((h^i)[0][0].Toll());
//        equations[1].push_back((h^i)[1][0].Toll());
//        equations[2].push_back((h^i)[0][2].Toll());
//        equations[3].push_back((h^i)[1][2].Toll());
//        equations[4].push_back((h^i)[2][2].Toll());
//    }
//    Mat c(equations);
//    cout << c << '\n';
//    c.Eliminate();
//    cout << c << '\n';
//};
//solver(0);