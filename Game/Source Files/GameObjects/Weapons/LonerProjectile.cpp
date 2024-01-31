#include "../Game/Headers/LonerProjectile.h"

LonerProjectile::~LonerProjectile()
{
	SDL_DestroyTexture(currentImage);
	currentImage = nullptr;
}
