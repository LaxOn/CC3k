#include "tiledecorator.h"

using namespace std;

TileDecorator::TileDecorator(shared_ptr<BasicTile> base) :
	base{base} {}

TileDecorator::~TileDecorator() {};
