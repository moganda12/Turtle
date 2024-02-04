#pragma once

void screwup(int code) {
	std::cerr << "Ye screwed up Screwup code: " << code << '\n';
	exit(code);
}