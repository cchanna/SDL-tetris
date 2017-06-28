//******************************************************************************
//**************************** TILES *******************************************
//******************************************************************************

TILE Board_GetTile(BOARD *board, int x, int y)
{
    TILE result = {};
    if (x >= 0 && x < board->width && y >= 0 && y < board->height)
    {
        result = board->tiles[(y * board->width) + x];
    }
    return result;
}

bool32 Board_TileExists(BOARD *board, int x, int y)
{
    return Board_GetTile(board, x, y).kind > 0;
}

void Board_SetTile(BOARD *board, int x, int y, TILE value)
{
    board->tiles[(y * board->width) + x] = value;
}

void Board_ClearTile(BOARD *board, int x, int y)
{
    board->tiles[(y * board->width) + x] = {};
}

void RotateTileOffsets(TILE_OFFSET out[4], TILE_OFFSET in[4], int count, int amount)
{
    amount *= -1;
    while (amount < 0) amount += 4;

    int8 sin = (int8)((amount % 4) - 2) % 2;
    int8 cos = (int8)(((amount + 3) % 4) - 2) %2;
    for (int i=0; i < count; i++)
    {
        int8 x = in[i].x;
        int8 y = in[i].y;
        out[i].x = (cos * x) + (sin * y);
        out[i].y = (-sin * x) + (cos * y);
    }
}
