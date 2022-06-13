#define CHMAT_UNSIGNED_CHAR     1
#define CHMAT_UNSIGNED_INT      2
#define CHMAT_INT               3
#define CHMAT_FLOAT             4
#define CHMAT_DOUBLE            5
static char bullet[5][5] = { {0,1,1,1,0},{0,0,1,0,0},{0,1,1,1,0},{0,1,1,1,0},{0,0,1,0,0} };
static char gameoverpixel[9][90] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,0},
    {0,1,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0},
    {0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0},
    {0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0},
    {0,0,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
static char scorepixel[7][38] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,0},
    {0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0},
    {0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,1,1,1,1,0,0,1,0,0,0,0,1,0,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
static char num0[5][5] = { {0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0} };
static char num1[5][5] = { {0,1,1,1,0},{0,0,1,0,0},{0,0,1,0,0},{0,1,1,0,0},{0,0,1,0,0} };
static char num2[5][5] = { {1,1,1,1,1},{1,0,0,0,0},{1,1,1,1,1},{0,0,0,0,1},{1,1,1,1,1} };
static char num3[5][5] = { {1,1,1,1,1},{0,0,0,0,1},{1,1,1,1,1},{0,0,0,0,1},{1,1,1,1,1} };
static char num4[5][5] = { {0,0,0,1,0},{1,1,1,1,1},{0,1,0,1,0},{0,0,1,1,0},{0,0,0,1,0} };
static char num5[5][5] = { {1,1,1,1,1},{0,0,0,0,1},{1,1,1,1,1},{1,0,0,0,0},{1,1,1,1,1} };
static char num6[5][5] = { {1,1,1,1,1},{1,0,0,0,1},{1,1,1,1,1},{1,0,0,0,0},{1,1,1,1,1} };
static char num7[5][5] = { {0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1},{1,1,1,1,1} };
static char num8[5][5] = { {1,1,1,1,1},{1,0,0,0,1},{1,1,1,1,1},{1,0,0,0,1},{1,1,1,1,1} };
static char num9[5][5] = { {1,1,1,1,1},{0,0,0,0,1},{1,1,1,1,1},{1,0,0,0,1},{1,1,1,1,1} };
static char spaceshippixel[1225] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1441792, 1310720, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0, 0, 2359296, 5046272, 0, 8192000, 8257536, 0, 0, 131072, 655360, 65536, 0, 655360, 655360, 655360, 131072, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 196608, 5701632, 917504, 7733248, 0, 5636096, 1441792, 6029312, 5701632, 0, 8060928, 8388608, 0, 0, 3211264, 64250, 4892576, 5608332, 64250, 64250, 64250, 1900544, 2686976, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 3407872, 57070, 13720, 327680, 2424832, 393216, 2097152, 1572864, 851968, 2424832, 1179648, 1245184, 2424832, 2424832, 65536, 19775, 18747, 18747, 18747, 18747, 18747, 44197, 7733248, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 983040, 1768958, 55018, 4587520, 2686976, 2162688, 4456448, 7733248, 4784128, 2686976, 6815744, 7077888, 2686976, 2686976, 1048576, 50624, 50367, 50367, 50367, 50367, 50367, 126700, 5177344, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1114112, 4063232, 393216, 0, 1245184, 0, 4128768, 8323072, 0, 8060928, 8388608, 0, 0, 2949120, 1376256, 31866, 26468, 26468, 26468, 53969, 7602176, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3932160, 3801088, 0, 0, 0, 2031616, 32122, 26725, 26725, 26725, 44974, 5505024, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2031616, 48572, 45745, 45745, 45745, 46001, 588538, 1048576, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2031616, 14388, 6163, 6163, 6163, 6163, 47030, 6553600, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2031616, 65021, 65021, 65021, 65021, 65021, 65278, 4194304, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2031616, 15673, 7705, 7705, 7705, 7705, 9761, 194294, 5505024, 4718592, 4718592, 2293760,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6225920, 720896, 48315, 45744, 45744, 45744, 45744, 52941, 56044, 52966, 62964, 53453, 1179648,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 524288, 36228, 35200, 35200, 35200, 35200, 35715, 65278, 5768, 17568, 55766, 19776, 65536,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1900544, 6815744, 7340032, 393216, 4456448, 7667712, 131072, 40599, 40085, 40085, 40085, 40085, 40599, 65022, 31676, 39627, 60137, 40855, 327680,
0, 0, 0, 0, 0, 0, 0, 0, 65536, 983040, 2555904, 4063232, 5636096, 7208960, 7995392, 4390912, 193522, 45484, 40085, 405281, 160104, 41114, 41114, 41114, 41114, 41114, 41114, 41114, 41114, 41114, 41114, 42143, 130814, 7340032, 6029312,
1245184, 5177344, 6750208, 8323072, 6946816, 5373952, 3801088, 2228224, 589824, 63479, 58338, 53196, 48054, 42913, 37515, 28517, 11808, 11552, 15665, 15665, 14893, 9752, 9752, 14636, 24148, 24148, 24148, 24148, 24148, 24148, 24148, 24405, 130043, 65536, 0,
2621440, 49381, 42458, 42971, 59623, 30060, 24662, 19520, 14122, 11037, 11037, 11037, 11037, 10266, 9752, 10266, 20806, 61421, 62442, 62442, 63989, 31345, 18750, 61422, 54481, 63736, 56280, 62450, 57566, 61164, 58851, 54224, 65278, 65536, 0,
65280, 5023, 4510, 16561, 65278, 64763, 64763, 64763, 64763, 64763, 64763, 64763, 64763, 51654, 9752, 49083, 65021, 48793, 26644, 26644, 45962, 37775, 33405, 46768, 16691, 57823, 25431, 52167, 31087, 45998, 37000, 16948, 64507, 65536, 0,
2621440, 49381, 42458, 42971, 59623, 29546, 24405, 19263, 13351, 10011, 9754, 9242, 8985, 8215, 7444, 7189, 17472, 61165, 61931, 61931, 63733, 28781, 15672, 61165, 53710, 63735, 55509, 62193, 57051, 60651, 58337, 53452, 65278, 65536, 0,
1245184, 5177344, 6750208, 8323072, 6946816, 5373952, 3801088, 2228224, 1571321, 7543318, 1554100, 52427, 46773, 41118, 35720, 25953, 8219, 7962, 12332, 12332, 11303, 5906, 5906, 11047, 21327, 21328, 21328, 21328, 21328, 21328, 21328, 21585, 130043, 65536, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1638400, 4063232, 5636096, 7208960, 7995392, 4390912, 193522, 44202, 39575, 39575, 39575, 39575, 39575, 39575, 39575, 39575, 39575, 39575, 39575, 39575, 39575, 40604, 130814, 7340032, 6029312,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1835008, 6815744, 7667712, 7667712, 7667712, 7667712, 131072, 40599, 40085, 40085, 40085, 40085, 40599, 65022, 31676, 39627, 60137, 40855, 327680,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 589824, 36228, 35200, 35200, 35200, 35200, 35715, 65278, 5768, 17568, 55766, 19776, 65536,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6225920, 720896, 48315, 45744, 45744, 45744, 45744, 52941, 56044, 52966, 62964, 53453, 1179648,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2031616, 16444, 8476, 8476, 8476, 8476, 10276, 194294, 5570560, 4718592, 4718592, 2293760,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2031616, 64250, 64250, 64250, 64250, 64250, 64764, 4194304, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2031616, 14388, 5906, 5906, 5906, 5906, 47030, 6619136, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2031616, 48572, 45745, 45745, 45745, 46001, 588538, 1048576, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3932160, 3801088, 0, 0, 0, 2031616, 32122, 26725, 26725, 26725, 44973, 5505024, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1179648, 4063232, 393216, 0, 1245184, 0, 4194304, 8323072, 0, 8060928, 8388608, 0, 0, 2949120, 1376256, 31866, 26468, 26468, 26468, 53969, 7602176, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 983040, 1768958, 55018, 4587520, 2686976, 2162688, 4456448, 7733248, 4784128, 2686976, 6815744, 7077888, 2686976, 2686976, 1048576, 50624, 50367, 50367, 50367, 50367, 50367, 126700, 5177344, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 3407872, 57070, 13720, 327680, 2424832, 393216, 2097152, 1572864, 851968, 2424832, 1179648, 1245184, 2424832, 2424832, 65536, 19776, 19004, 19004, 19004, 19004, 19004, 44197, 7798784, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 196608, 5701632, 1114112, 7733248, 0, 5636096, 1441792, 6029312, 5701632, 0, 8060928, 8388608, 0, 0, 3276800, 64507, 64506, 64506, 64506, 64506, 64507, 1966080, 2686976, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2359296, 5046272, 0, 8192000, 8257536, 0, 0, 65536, 524288, 524288, 524288, 524288, 524288, 524288, 65536, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1376256, 1310720, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


class CHMAT
{
public:
    //members
    int X = 0, Y = 0, type = 0;
    void* data = 0;
    HBITMAP HBitmap; //bitmap handle
    //---constructer & destructor ---------------------
    CHMAT(int x, int y, int typ);
    ~CHMAT();
    //---methods ---------------------
    int set(int x, int y, int val);
    void print_mat();
    //---operators ------------------
    void operator = (int a);
    void operator += (int a);
    int& operator () (int x, int y);
    
};
