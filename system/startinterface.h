#pragma once
#include <deque>
#include <vector>
#include "point.h"

	class startInterface
	{
	public:
		startInterface() : speed(35) {
			starts.emplace_back(Point(0, 14));
			starts.emplace_back(Point(1, 14));
			starts.emplace_back(Point(2, 15));
			starts.emplace_back(Point(3, 16));
			starts.emplace_back(Point(4, 17));
			starts.emplace_back(Point(5, 18));
			starts.emplace_back(Point(6, 17));
			starts.emplace_back(Point(7, 16));
			starts.emplace_back(Point(8, 15));
			starts.emplace_back(Point(9, 14));
			//s
			textsystem.emplace_back(Point(-26, 14));
			textsystem.emplace_back(Point(-25, 14));
			textsystem.emplace_back(Point(-27, 15));
			textsystem.emplace_back(Point(-26, 16));
			textsystem.emplace_back(Point(-25, 17));
			textsystem.emplace_back(Point(-27, 18));
			textsystem.emplace_back(Point(-26, 18));
			//y
			textsystem.emplace_back(Point(-23, 15));
			textsystem.emplace_back(Point(-18, 15));
			textsystem.emplace_back(Point(-22, 16));
			textsystem.emplace_back(Point(-21, 17));
			textsystem.emplace_back(Point(-20, 18));
			textsystem.emplace_back(Point(-19, 16));
			textsystem.emplace_back(Point(-20, 17));
			textsystem.emplace_back(Point(-21, 18));
			//s
			textsystem.emplace_back(Point(-15, 14));
			textsystem.emplace_back(Point(-14, 14));
			textsystem.emplace_back(Point(-16, 15));
			textsystem.emplace_back(Point(-15, 16));
			textsystem.emplace_back(Point(-14, 17));
			textsystem.emplace_back(Point(-16, 18));
			textsystem.emplace_back(Point(-15, 18));
			//t
			textsystem.emplace_back(Point(-10, 14));
			textsystem.emplace_back(Point(-10, 15));
			textsystem.emplace_back(Point(-10, 16));
			textsystem.emplace_back(Point(-10, 17));
			textsystem.emplace_back(Point(-10, 18));
			textsystem.emplace_back(Point(-12,14));
			textsystem.emplace_back(Point(-11, 14));
			textsystem.emplace_back(Point(-10, 14));
			textsystem.emplace_back(Point(-9, 14));
			textsystem.emplace_back(Point(-8, 14));
			//E
			textsystem.emplace_back(Point(-6, 14));
			textsystem.emplace_back(Point(-6, 15));
			textsystem.emplace_back(Point(-6, 16));
			textsystem.emplace_back(Point(-6, 17));
			textsystem.emplace_back(Point(-6, 18));
			textsystem.emplace_back(Point(-5, 14));
			textsystem.emplace_back(Point(-5, 16));
			textsystem.emplace_back(Point(-5, 18));
			textsystem.emplace_back(Point(-4, 14));
			textsystem.emplace_back(Point(-4, 16));
			textsystem.emplace_back(Point(-4, 18));
			//m
			textsystem.emplace_back(Point(-1, 18));
			textsystem.emplace_back(Point(0, 17));
			textsystem.emplace_back(Point(1, 16));
			textsystem.emplace_back(Point(2, 15));
			textsystem.emplace_back(Point(2, 14));

			textsystem.emplace_back(Point(3, 14));
			textsystem.emplace_back(Point(4, 15));
			textsystem.emplace_back(Point(5, 16));
			textsystem.emplace_back(Point(4, 16));
			textsystem.emplace_back(Point(5, 15));
			textsystem.emplace_back(Point(6, 14));

			textsystem.emplace_back(Point(7, 14));
			textsystem.emplace_back(Point(7, 15));
			textsystem.emplace_back(Point(8, 16));
			textsystem.emplace_back(Point(9, 17));
			textsystem.emplace_back(Point(10, 18));
		
			


		}
		void PrintFirst();
		void PrintSecond();
		void PrintThird();
		void PrintText();
		void ClearText();
		void Action();
	private:
		deque<Point> starts;//开始动画中的线
		vector<Point> textsystem;//开始动画中的文字
		int speed;//动画的速度
};

