#include <iostream>

//Made this while completing the online course "Algorithms: Design and Analysis" at Stanford Lagunita 

void merge_sort(int* p_array, int size) {
	if (size == 1)
		return;

	int odd = size & 1 ? 1 : 0;
	int* arr_a = p_array;
	int* arr_b = p_array + (size / 2);

	merge_sort(arr_a, size / 2);
	merge_sort(arr_b, size / 2 + odd);

	int* temp_array = new int[size];
	int arr_a_index = 0;
	int arr_b_index = 0;

	for (int i = 0; i < size; i++) {
		if (arr_a_index >= size / 2) {
			temp_array[i] = arr_b[arr_b_index++];
			continue;
		}
		if (arr_b_index >= size / 2 + odd) {
			temp_array[i] = arr_a[arr_a_index++];
			continue;
		}
		temp_array[i] = arrA[arr_a_index] < arrB[arr_b_index] ? arrA[arr_a_index++] : arrB[arr_b_index++];
	}

	for (int i = 0; i < size; i++) {
		p_array[i] = temp_array[i];
	}
	delete[] temp_array;
	return;
}

int main()
{
	int number_array[] = { 9219, 4720, 1456, 10384, 3682, 10366, 1960, 4006, 8327, 1624, 5236, 1431, 1098, 9946, 3977, 9751, 10573, 11872, 10994, 984, 770, 11438, 9399, 10252, 8458, 3794, 10719, 8814, 2991, 11797, 3822, 2403, 3158, 2091, 5148, 10039, 3930, 3208, 7505, 10030, 10315, 5158, 3802, 7996, 2425, 2442, 9005, 2063, 6999, 4186, 954, 2231, 4650, 8146, 10037, 8520, 6559, 273, 10008, 1554, 5473, 10551, 86, 6721, 2844, 664, 10499, 7188, 2842, 731, 431, 10910, 8936, 8212, 10764, 2621, 3450, 1230, 11012, 5425, 10998, 8046, 6223, 10548, 2789, 3727, 10831, 8441, 10363, 4978, 7515, 7293, 7103, 10902, 492, 10695, 9994, 8074, 9125, 1882, 1280, 614, 9966, 9818, 10063, 5180, 433, 6289, 9579, 5117, 8006, 10381, 2916, 6195, 1634, 4359, 4236, 11757, 5129, 2421, 8401, 9300, 9778, 9714, 5622, 11510, 9985, 3314, 6006, 1672, 6085, 9226, 3909, 2383, 8302, 2393, 6240, 11045, 10881, 451, 7383, 9453, 8797, 4666, 720, 17, 4992, 4755, 8306, 8693, 2009, 8651, 4221, 1220, 1143, 5804, 9497, 4129, 10377, 350, 7502, 8967, 5792, 5274, 8957, 2648, 9730, 7386, 2484, 3394, 2111, 1628, 318, 4663, 6303, 10313, 6601, 9716, 10490, 8509, 4312, 2156, 3236, 1039, 10917, 6275, 3704, 184, 7626, 2141, 8274, 8952, 5226, 5886, 4142, 11468, 1205, 1553, 4153, 10445, 8058, 6897, 1092, 8810, 3062, 8418, 1428, 11800, 5961, 3881, 4348, 11119, 11133, 1966, 9813, 9051, 4011, 1520, 5490, 2040, 11351, 4209, 9590, 1266, 1379, 1579, 7224, 5941, 10759, 745, 8709, 11932, 7827, 8033, 9840, 878, 10309, 3839, 9361, 1162, 2749, 8227, 1497, 6953, 4518, 362, 10187, 6770, 3303, 2211, 6792, 2335, 10590, 5441, 7591, 547, 6819, 11927, 6079, 2595, 10089, 11798, 11446, 2530, 3705, 8773, 10167, 2918, 2985, 9231, 1696, 4745, 3446, 6121, 9678, 3689, 2896, 4524, 10533, 8497, 3919, 7693, 6794, 465, 7872, 4793, 3365, 7141, 6105, 7227, 3722, 9350, 11884, 1962, 2033, 7598, 7917, 8203, 10502, 8353, 6425, 8896, 8786, 7399, 7560, 7507, 4315, 1739, 10595, 3788, 334, 9909, 1964, 4421, 10959, 6629, 5841, 6049, 9353, 10285, 9639, 3629, 5882, 9806, 11826, 9029, 10346, 8324, 8976, 1277, 3424, 6847, 5008, 4947, 6948, 10135, 8276, 5967, 623, 7904, 6884, 6556, 1842, 4340, 2482, 11181, 458, 7824, 152, 9106, 6218, 8760, 927, 10797, 9903, 6108, 9270, 8240, 4083, 9662, 6740, 1950, 6155, 7789, 1521, 6858, 8740, 3755, 11196, 1024, 8700, 937, 3621, 7493, 2245, 7769, 4651, 4825, 2044, 7605, 10541, 8747, 9320, 571, 2204, 10322, 8470, 8182, 8714, 4002, 750, 6258, 9061, 7240, 6411, 3973, 9318, 10161, 6823, 11960, 2945, 4665, 165, 3469, 10462, 4801, 8005, 1355, 11392, 6202, 3380, 8846, 8223, 3587, 2350, 964, 7071, 3440, 11229, 7246, 5772, 8414, 5182, 8679, 10014, 2852, 259, 7664, 1899, 159, 7458, 11302, 2430, 7992, 5017, 3761, 10955, 8152, 6709, 8268, 366, 11894, 8443, 562, 11867, 7404, 6669, 7305, 268, 8179, 8417, 683, 6982, 11893, 859, 8649, 220, 6244, 6380, 8024, 1291, 319, 9740, 4612, 6162, 945, 2665, 1334, 10195, 10070, 11535, 3623, 10931, 1591, 11111, 3254, 8518, 10877, 4760, 10238, 9899, 8596, 3616, 449, 3403, 4606, 10241, 1131, 4290, 1600, 1223, 5953, 5384, 3496, 1405, 2100, 11922, 8953, 7285, 4048, 2174, 1225, 11175, 5471, 4035, 5324, 2778, 4662, 6093, 7634, 6684, 4202, 7671, 6643, 8517, 3193, 6950, 6083, 11034, 10494, 8871, 80, 1232, 11924, 8671, 7384, 2645, 8298, 1674, 11421, 3801, 10793, 8423, 1873, 1757, 9742, 10580, 2285, 4564, 6722, 8503, 2646, 9330, 7262, 10455, 1928, 5066, 5077, 5268, 3993, 382, 10888, 9132, 2473, 11905, 9529, 11836, 5147, 7311, 3658, 2855, 4943, 5214, 11568, 11903, 10889, 7270, 10845, 7421, 10750, 6931, 3659, 8603, 3670, 4287, 49, 11332, 222, 3887, 4668, 11641, 251, 7731, 5780, 2652, 5205, 4409, 6507, 3392, 9062, 869, 11084, 7839, 972, 8235, 1627, 8199, 192, 480, 7724, 9850, 6744, 10885, 7203, 7446, 2602, 10286, 9314, 4583, 7412, 2498, 1742, 824, 4537, 10251, 3372, 1186, 7036, 2494, 1202, 1410, 3233, 9440, 2962, 5135, 10650, 6413, 3207, 2170, 11317, 10128, 5662, 5584, 6498, 6805, 4396, 8399, 3524, 10389, 2862, 10043, 6281, 8650, 9640, 8395, 3512, 5950, 2537, 11314, 2106, 4694, 8384, 1791, 9927, 2626, 5898, 11271, 11965, 10643, 3332, 8390, 10855, 514, 377, 11719, 926, 3798, 10077, 6712, 2344, 6688, 6748, 9041, 10311, 5124, 6466, 1156, 10284, 4397, 3975, 4683, 3574, 9033, 3979, 1429, 5800, 3178, 10674, 11471, 3536, 10147, 8214, 1312, 7993, 5480, 3866, 5698, 1118, 9578, 2165, 6007, 2113, 4016, 1932, 10497, 11415, 755, 5949, 6430, 6657, 9008, 3775, 4249, 316, 10657, 6044, 7409, 10159, 10107, 814, 8034, 4497, 10002, 11509, 2783, 11920, 8176, 2192, 1211, 11065, 4361, 2308, 7875, 9189, 8818, 2017, 8035, 6834, 11006, 9138, 2533, 1134, 2028, 4078, 6383, 10395, 1592, 8132, 3613, 3527, 7337, 5112, 11494, 6944, 10154, 1564, 9431, 10715, 8677, 9672, 214, 5699, 9761, 11441, 9448, 9104, 1274, 7082, 582, 5906, 2992, 5215, 1640, 2895, 1551, 6528, 3230, 438, 8694, 11656, 751, 7887, 7003, 6765, 3325, 11396, 7869, 4332, 499, 10868, 10802, 11845, 352, 3010, 2417, 6174, 10175, 4532, 5833, 8610, 8177, 7378, 11190, 4190, 1503, 8974, 7106, 3917, 2351, 7307, 7335, 8153, 1388, 7984, 8231, 4195, 5292, 4749, 358, 4621, 9824, 1369, 4483, 8623, 4966, 11986, 8308, 9557, 4515, 1401, 10113, 5013, 3220, 11520, 8654, 2619, 10840, 11825, 707, 1974, 1546, 5156, 896, 5039, 3814, 2458, 10671, 6731, 4187, 1370, 10807, 9379, 6994, 5956, 162, 1165, 793, 970, 10788, 3684, 1773, 9491, 11812, 5677, 7129, 7780, 217, 477, 3037, 11448, 11452, 669, 10376, 2949, 1126, 11925, 9675, 11724, 691, 11233, 11228, 10244, 4579, 6073, 10038, 11018, 805, 1064, 4610, 10972, 5799, 3950, 9470, 5719, 3433, 9800, 4286, 2660, 3987, 4809, 8243, 3999, 11249, 7196, 10227, 6987, 243, 126, 4386, 7369, 9997, 8304, 10410, 429, 2016, 9292, 5863, 4334, 1637, 11563, 7078, 1851, 9563, 5965, 1614, 2559, 4112, 2750, 10500, 11811, 10712, 5023, 1307, 3021, 10411, 6979, 6968, 5655, 2618, 3436, 1302, 2514, 11906, 8719, 8356, 78, 8588, 11762, 822, 9071, 4977, 344, 1723, 6056, 2443, 6705, 2398, 6449, 711, 2268, 818, 9193, 9436, 2296, 8869, 3929, 3519, 2592, 995, 5829, 3622, 10412, 3283, 6679, 5320, 2846, 5924, 9661, 3143, 8140, 8772, 6621, 7091, 4087, 6807, 11184, 9601, 11680, 6579, 5969, 2837, 7607, 3937, 1683, 2710, 9705, 958, 5224, 11211, 4201, 3260, 3428, 1698, 229, 6700, 804, 4299, 2506, 363, 7254, 3781, 5081, 2570, 10228, 8572, 11589, 485, 6840, 9321, 2373, 5246, 5426, 8291, 6850, 2065, 2179, 5433, 4451, 10982, 6251, 9710, 11125, 81, 2407, 2096, 674, 281, 6572, 1947, 8890, 7170, 8562, 2781, 400, 9926, 3266, 8722, 5245, 4429, 1183, 8129, 501, 7742, 6745, 10562, 10946, 8340, 11731, 2132, 3096, 9002, 7198, 3438, 4553, 8553, 8664, 11655, 1468, 151, 8884, 8920, 9984, 941, 1710, 11874, 3483, 7810, 3607, 9735, 4576, 10342, 5078, 4791, 475, 1846, 10772, 3301, 2026, 6010, 11855, 1067, 9866, 10040, 676, 1090, 6593, 11219, 7707, 3680, 3859, 6118, 2210, 8174, 3098, 518, 938, 10740, 3595, 6757, 769, 8751, 4200, 6499, 6180, 203, 10153, 3439, 11771, 4872, 2812, 7402, 4366, 1782, 821, 8609, 4586, 2738, 8711, 5589, 3585, 9317, 1770, 11291, 5386, 5436, 6214, 2360, 1204, 3471, 8922, 1648, 8798, 8083, 9538, 2615, 11877, 8263, 1690, 10350, 3939, 6689, 2083, 1198, 10782, 1538, 502, 2128, 1171, 3046, 232, 4592, 3823, 8489, 2523, 4001, 7193, 11241, 5444, 6560, 2483, 11714, 11550, 7509, 10649, 2706, 5278, 1559, 5442, 1145, 8639, 11551, 8305, 7084, 9284, 11282, 4942, 11959, 7941, 5650, 263, 6503, 11118, 9877, 1984, 9967, 9569, 2169, 5971, 5025, 6720, 7035, 183, 5896, 9534, 3514, 2314, 2642, 8010, 11962, 3219, 11323, 8592, 1222, 4122, 5407, 9163, 8408, 10960, 10610, 5695, 9797, 9638, 9553, 10456, 6558, 3378, 9854, 3363, 9868, 6414, 8406, 285, 9298, 9392, 6329, 8787, 2515, 7968, 2740, 1139, 1610, 7530, 9837, 3330, 390, 4117, 10026, 5947, 4419, 6229, 7476, 4667, 3454, 6975, 5611, 452, 10439, 3603, 6095, 11330, 1483, 561, 8726, 3005, 3910, 11199, 11038, 11970, 10453, 10928, 4031, 1484, 8236, 333, 7514, 10504, 5877, 7990, 4206, 6548, 7957, 9246, 9490, 3161, 3391, 6319, 694, 6286, 1781, 5142, 4907, 4433, 6197, 5185, 7352, 10729, 7137, 8462, 1142, 8842, 4702, 4373, 5487, 655, 5876, 6604, 10612, 6199, 1814, 3879, 9757, 4345, 7202, 2449, 4503, 1540, 7698, 10278, 7642, 7039, 8803, 4686, 10594, 2901, 10752, 2581, 11529, 9652, 11454, 7919, 6394, 6064, 5530, 10965, 10085, 3855, 9857, 6995, 11862, 560, 6332, 1478, 4888, 1305, 8337, 7790, 2058, 9594, 7255, 8934, 4355, 3318, 8466, 2830, 634, 1811, 6896, 1449, 4096, 5520, 9224, 3289, 6714, 3562, 6839, 5396, 4448, 1772, 1858, 6890, 6739, 6101, 581, 5003, 8983, 5812, 5735, 3339, 3969, 5221, 6024, 7927, 4919, 4797, 371, 10273, 6949, 3044, 1622, 8245, 1328, 8113, 2260, 4220, 3206, 5968, 646, 10622, 6315, 11506, 1104, 2527, 11538, 5118, 7251, 8820, 4148, 10261, 10233, 4258, 2638, 1681, 3048, 6433, 939, 8332, 3374, 9844, 6576, 6339, 6427, 1821, 7714, 300, 4353, 6028, 10891, 7013, 6816, 13, 11137, 10196, 9700, 1746, 2025, 6497, 5001, 10583, 489, 2573, 6781, 4940, 1831, 991, 7125, 5632, 11192, 8292, 3835, 8145, 10570, 2235, 11738, 2364, 9523, 10414, 10367, 1043, 5391, 5653, 5526, 11774, 3172, 7221, 11265, 1365, 2880, 624, 6440, 7677, 8343, 4491, 11289, 11643, 1662, 809, 3818, 2185, 3240, 541, 6032, 10607, 7592, 9928, 9006, 4229, 914, 7121, 6871, 8641, 64, 931, 418, 2857, 7462, 5542, 231, 788, 7171, 3545, 2504, 1594, 10701, 2164, 5307, 6793, 7076, 4845, 7545, 8411, 282, 10944, 3167, 233, 6511, 10297, 7716, 8917, 2612, 1381, 1368, 9482, 11010, 9815, 11202, 5762, 4263, 5298, 883, 10117, 11279, 2339, 180, 7268, 2415, 5369, 9846, 3875, 1983, 3032, 3498, 3649, 8455, 1348, 5560, 10909, 5696, 1321, 1731, 8434, 5964, 2538, 4927, 5021, 7531, 8550, 5060, 4862, 9622, 190, 7241, 6488, 6212, 5154, 748, 3795, 2381, 9833, 5686, 9600, 11609, 8621, 9135, 2526, 3850, 5317, 10084, 3943, 9697, 2687, 9236, 9786, 7453, 3955, 4188, 3190, 11244, 10269, 399, 9613, 8477, 969, 2082, 10372, 1854, 6600, 5722, 3611, 8158, 4210, 11481, 10471, 2372, 5543, 6966, 7566, 101, 10611, 5807, 8628, 8483, 7709, 6636, 2913, 10036, 10365, 4133, 10035, 7720, 2544, 4090, 6775, 601, 2243, 10250, 7073, 10683, 11542, 8098, 3250, 3854, 6475, 11492, 8630, 3840, 10851, 574, 9363, 9869, 4708, 7299, 7688, 2649, 3678, 1527, 3126, 8382, 7831, 6934, 870, 406, 4305, 3081, 8107, 8756, 4185, 4493, 5465, 5280, 3358, 11767, 8049, 6553, 902, 8567, 10745, 6695, 2953, 10156, 6732, 11505, 983, 11412, 3047, 11651, 8134, 230, 1127, 8350, 7765, 3249, 3183, 4830, 8032, 9831, 5484, 7213, 6102, 4215, 8105, 911, 7273, 6088, 9721, 1407, 6929, 9702, 1446, 1411, 11047, 7339, 7890, 8933, 4798, 2278, 3327, 2225, 739, 1841, 5955, 11944, 7194, 10099, 6923, 2326, 11682, 9934, 4174, 10962, 5495, 4462, 5002, 1718, 5773, 1785, 767, 11690, 6546, 10947, 10004, 7737, 8849, 6635, 8407, 6193, 2431, 10194, 11557, 2522, 2094, 3981, 16, 2703, 8765, 8743, 4045, 7024, 10829, 6453, 4151, 3906, 2528, 8290, 3634, 4456, 8285, 4960, 15, 5120, 7377, 2609, 3247, 2036, 1839, 3349, 11475, 6021, 11328, 960, 7739, 11248, 3292, 307, 11066, 3646, 6651, 8029, 1860, 2230, 11676, 7708, 6205, 3605, 3891, 5808, 3809, 8454, 422, 7829, 117, 3744, 2976, 8681, 10538, 3104, 9920, 3821, 2935, 10979, 4360, 2265, 9554, 4376, 6300, 11405, 6726, 3489, 9100, 6868, 9370, 4823, 11600, 11254, 3177, 4033, 4157, 11092, 5511, 6909, 11097, 4487, 507, 7449, 780, 2153, 6468, 9636, 2406, 258, 10995, 1788, 3065, 10158, 83, 9916, 360, 2452, 1609, 6962, 8421, 4877, 7567, 10051, 11947, 9695, 7970, 5635, 7599, 4459, 11888, 1890, 1810, 3633, 1383, 5238, 10248, 8769, 7985, 8072, 8716, 10131, 5747, 188, 8972, 1150, 8723, 5636, 4762, 11284, 8525, 150, 3989, 10436, 11815, 8045, 6586, 4282, 6573, 7535, 7085, 5973, 504, 7754, 10604, 4870, 2539, 6397, 4873, 2103, 2694, 3058, 6891, 8824, 5545, 7882, 9182, 2286, 11238, 9412, 6981, 3267, 4021, 3799, 4624, 9303, 4725, 6419, 7430, 9156, 10443, 4470, 9031, 635, 7096, 3322, 11372, 2146, 3153, 2924, 4372, 4053, 4018, 4028, 11207, 7294, 3852, 3578, 9244, 11773, 10721, 7955, 4019, 3042, 8115, 44, 10116, 10908, 6439, 10579, 11828, 8782, 9217, 5791, 4222, 372, 6474, 7134, 2891, 6220, 11061, 9136, 6385, 9468, 10109, 5234, 10405, 139, 10755, 7314, 3560, 303, 6330, 9273, 104, 2722, 661, 4898, 9543, 4560, 10245, 2898, 2152, 11136, 11611, 741, 1993, 10779, 11928, 11482, 11955, 7491, 108, 950, 5247, 5018, 9180, 3179, 10388, 6057, 9080, 5746, 2453, 7755, 1436, 5314, 10086, 7122, 5220, 4711, 2930, 7324, 971, 698, 10437, 10837, 4235, 1849, 1531, 157, 6018, 10, 11628, 8538, 10651, 247, 8635, 1338, 8978, 8329, 2620, 9264, 3759, 1792, 4088, 5960, 11916, 11205, 142, 9960, 3213, 3807, 5710, 5330, 2756, 4267, 11003, 2840, 949, 11788, 3849, 7390, 4054, 11716, 8120, 9478, 3369, 835, 170, 1994, 1844, 1399, 4514, 90, 1702, 9012, 5033, 932, 168, 2318, 3056, 2867, 2697, 609, 2937, 1060, 6112, 4420, 2885, 2205, 1855, 5011, 5843, 11215, 901, 5387, 10544, 11297, 11342, 3396, 575, 10912, 9134, 7954, 2919, 10633, 1929, 2013, 176, 10521, 7836, 8524, 3911, 6899, 9911, 6137, 9588, 5310, 5232, 536, 3921, 5489, 3601, 1350, 1003, 1154, 3982, 12, 3480, 771, 5281, 5411, 414, 2134, 8059, 10925, 9863, 10450, 7787, 8349, 1010, 2599, 5237, 6322, 5846, 2633, 1953, 4098, 6296, 5100, 4664, 1233, 8921, 9623, 9487, 466, 3747, 2973, 4617, 4351, 813, 10776, 4435, 30, 2723, 9655, 9921, 650, 2926, 3845, 6282, 4082, 9374, 3463, 10821, 2283, 10444, 4158, 7750, 516, 10075, 8775, 1327, 1416, 9183, 24, 6596, 1078, 9936, 11778, 1913, 8156, 9203, 4480, 3262, 3386, 10709, 367, 7212, 2379, 5096, 4773, 6933, 2469, 3493, 427, 1208, 7083, 1030, 2820, 3886, 10808, 10413, 9897, 1504, 10571, 2832, 2796, 2978, 8314, 6317, 7524, 6527, 2601, 5045, 2511, 6345, 6263, 8705, 11456, 1892, 211, 376, 2387, 11021, 7791, 10406, 10672, 5506, 9973, 651, 9111, 3482, 7049, 8807, 7833, 1447, 6053, 10848, 5738, 7608, 2401, 1329, 5446, 8191, 3019, 4385, 11708, 4388, 3952, 3931, 5305, 2509, 9825, 226, 885, 1795, 8685, 11112, 1688, 6154, 7075, 2672, 1059, 5451, 4709, 1180, 5183, 9593, 591, 8720, 6730, 8147, 6649, 11131, 8016, 11822, 198, 6184, 7870, 2368, 9390, 8501, 4738, 1938, 5623, 4549, 8468, 11515, 2941, 3244, 3505, 2465, 1214, 9429, 4347, 3200, 4180, 3571, 6059, 9788, 11163, 11951, 5389, 1587, 4961, 8301, 5321, 9598, 4641, 4571, 1752, 5867, 2518, 2269, 1868, 6500, 6680, 1435, 8, 7093, 9038, 10760, 9050, 2541, 4075, 910, 2979, 8864, 7394, 6762, 6990, 3675, 11540, 2290, 5249, 1819, 315, 10177, 9827, 2786, 11674, 7584, 6254, 4693, 3071, 5111, 1167, 5982, 4272, 10243, 7361, 3676, 7100, 8858, 1002, 10768, 7951, 2829, 11074, 8437, 4850, 10110, 7730, 3057, 7119, 2572, 277, 7891, 5557, 138, 10380, 5706, 7411, 5172, 2587, 2080, 2952, 2894, 3905, 1780, 2133, 4177, 7315, 6384, 7284, 679, 10508, 94, 2817, 9938, 5600, 11394, 8928, 4317, 8892, 9485, 2647, 1973, 864, 1344, 6906, 2161, 2195, 4452, 1031, 6886, 10407, 7455, 2728, 391, 630, 4404, 9521, 3442, 2747, 8645, 6061, 4457, 1576, 6766, 7396, 6293, 71, 6372, 9171, 9117, 6271, 326, 2594, 2546, 5862, 3882, 9795, 6434, 3685, 6246, 6590, 8932, 9437, 7301, 10901, 6513, 8531, 4012, 7429, 3537, 6804, 491, 657, 9643, 490, 8017, 4789, 4143, 8612, 6005, 3526, 6977, 10535, 6768, 666, 891, 3666, 7892, 9545, 2763, 7318, 8312, 11020, 6003, 643, 8508, 10706, 663, 4604, 4963, 10210, 840, 11307, 10563, 385, 7406, 2625, 8828, 2611, 5708, 65, 5065, 3857, 9762, 3014, 7546, 1726, 11312, 9152, 9790, 7834, 9950, 7826, 2622, 5227, 7971, 5230, 6321, 1492, 9290, 3144, 5218, 6334, 7260, 4234, 7489, 11914, 8827, 7926, 4956, 5024, 10786, 10129, 9608, 9747, 2543, 196, 5604, 8318, 5648, 1200, 4392, 7597, 5073, 6368, 7857, 3964, 1583, 5044, 3746, 9803, 11294, 11027, 6037, 3628, 8636, 2305, 9014, 9265, 4810, 5032, 5652, 3148, 1433, 3253, 11948, 10301, 3030, 6017, 7776, 9835, 1589, 7342, 255, 10428, 10022, 6717, 6854, 7312, 3827, 9373, 6616, 2410, 7081, 846, 6483, 4146, 10058, 7551, 11784, 7053, 7079, 4242, 10264, 2427, 2831, 7773, 11900, 6924, 3297, 9121, 10659, 409, 7494, 2053, 322, 7088, 76, 747, 5901, 11895, 2060, 186, 5138, 6423, 11295, 10665, 2317, 11861, 9852, 5873, 3902, 1499, 11890, 4059, 2577, 11649, 10985, 11816, 7901, 9614, 9383, 774, 10467, 875, 3091, 6703, 11588, 6309, 7674, 1213, 659, 11946, 1382, 9336, 1697, 6607, 8888, 8030, 6163, 8752, 6338, 8415, 9902, 6209, 5207, 5559, 10298, 9674, 8388, 161, 9255, 9393, 8225, 4955, 5377, 7618, 6398, 9736, 6222, 2490, 1323, 9883, 611, 4628, 1968, 7930, 9377, 2365, 7405, 10163, 2712, 8826, 4034, 6219, 3586, 3276, 10856, 6359, 6428, 8026, 5861, 8549, 9407, 2196, 7387, 4492, 5405, 11614, 2201, 10735, 4999, 3162, 8449, 9126, 218, 10542, 6370, 2325, 2012, 8336, 4718, 10506, 2402, 9426, 10100, 11952, 10673, 2909, 9103, 10561, 556, 3321, 9780, 974, 4289, 1452, 6852, 11989, 8467, 6327, 474, 11183, 4237, 533, 6813, 9423, 9045, 1331, 7685, 1679, 4240, 10907, 9872, 2839, 893, 5257, 9153, 11866, 8691, 2741, 238, 10105, 6791, 3742, 5213, 1393, 4779, 981, 8125, 4062, 1055, 4949, 11134, 4526, 3949, 9450, 7889, 6754, 2236, 7385, 6743, 8968, 7981, 8440, 6072, 5223, 10336, 1729, 6587, 6603, 1885, 8954, 10890, 55, 10132, 10341, 2471, 2409, 3530, 1004, 5757, 4046, 1933, 808, 8666, 9234, 11664, 11292, 1789, 434, 3076, 738, 11168, 11596, 1549, 10746, 354, 9354, 4645, 9358, 7360, 8542, 9913, 3972, 11440, 1694, 10351, 9465, 4463, 8539, 598, 11939, 6784, 1541, 11170, 8121, 10771, 386, 11898, 11095, 1920, 7120, 7344, 3793, 5188, 2315, 5152, 8233, 9599, 4256, 633, 8614, 2640, 9269, 7527, 768, 5144, 5435, 5351, 3165, 3946, 1253, 10287, 8272, 7015, 2188, 5528, 5805, 5605, 6255, 11560, 6970, 8076, 461, 7516, 7695, 9324, 6785, 225, 4984, 5667, 440, 8571, 7148, 1017, 1649, 11521, 1943, 9147, 8187, 4557, 10225, 5790, 6543, 1935, 2257, 9518, 8048, 6985, 2348, 3575, 1470, 977, 5028, 9139, 5858, 9664, 7225, 531, 4356, 656, 4469, 3724, 10019, 10246, 3470, 1670, 3592, 9551, 7520, 457, 7880, 4561, 596, 2823, 6674, 5593, 5313, 4052, 10983, 9645, 10266, 11559, 7286, 4692, 6980, 8534, 2312, 7174, 8575, 11275, 9498, 1354, 10963, 6051, 8484, 381, 9513, 1501, 2186, 8519, 8051, 11311, 10011, 1318, 7151, 11333, 10892, 3368, 8493, 6236, 8161, 10945, 4915, 11660, 1426, 2226, 3695, 401, 2400, 839, 819, 1422, 9654, 7220, 5497, 7021, 9188, 5266, 10739, 6280, 9185, 7549, 9670, 3468, 9541, 9191, 873, 1692, 4461, 753, 3093, 2902, 3538, 900, 10722, 2229, 7959, 1519, 2341, 3864, 1084, 9365, 7257, 2137, 2213, 9174, 3421, 860, 10621, 8947, 7300, 11875, 10282, 3988, 6646, 1112, 2801, 5519, 3551, 7054, 2361, 11843, 132, 5055, 1676, 8359, 8371, 7112, 7428, 5580, 8080, 87, 4705, 356, 9774, 4841, 11382, 288, 2470, 4835, 10485, 9873, 8839, 4814, 9115, 9464, 7371, 3615, 10398, 4596, 112, 3195, 9494, 10495, 11444, 8499, 6969, 1800, 11141, 5587, 4615, 129, 11313, 9319, 10433, 1005, 299, 6269, 5173, 11019, 7974, 8451, 4510, 9932, 2209, 9530, 6654, 11126, 7905, 3477, 8739, 3273, 2858, 3591, 7838, 7749, 1123, 8867, 10654, 5942, 11755, 6885, 5999, 4444, 10878, 10170, 7105, 1959, 4934, 4933, 4680, 7098, 1271, 6565, 11896, 5349, 5672, 1907, 4437, 8749, 459, 11488, 4268, 3550, 9009, 10981, 1364, 7201, 8812, 8971, 5061, 3192, 9572, 308, 5925, 6708, 1238, 3785, 7656, 4295, 9611, 3443, 2932, 9738, 8184, 8241, 6031, 11197, 10677, 10165, 944, 6237, 3991, 10803, 10865, 9962, 2234, 7931, 8557, 7561, 7863, 3992, 6261, 8893, 2359, 2200, 9022, 4616, 6878, 10785, 2102, 11187, 602, 7470, 6606, 11572, 6260, 11705, 5666, 4475, 10641, 10151, 7767, 6473, 11007, 3956, 11993, 9510, 179, 7989, 1300, 10140, 10215, 1585, 2353, 3023, 2049, 8351, 5865, 3663, 4843, 5811, 10281, 11327, 1361, 10059, 8014, 10906, 7650, 11530, 9329, 1834, 4107, 8222, 9279, 5938, 6139, 4727, 5874, 4594, 4901, 10899, 6122, 7874, 3402, 7287, 9472, 8802, 11026, 10823, 9084, 10104, 8561, 6591, 10474, 1850, 1073, 6662, 4352, 6481, 5094, 221, 10727, 9140, 9503, 11068, 3738, 8066, 2166, 6668, 2628, 4175, 4731, 1740, 5727, 4010, 3164, 10142, 6432, 5742, 10646, 1087, 9343, 5468, 1840, 11071, 6076, 11364, 10707, 11502, 5322, 11143, 986, 10826, 11689, 10934, 7468, 9961, 7568, 7661, 6510, 779, 10560, 5263, 4418, 41, 5645, 6182, 975, 1311, 11455, 648, 4160, 2658, 3344, 7936, 9215, 1548, 9631, 6925, 10487, 3770, 3242, 7277, 227, 156, 3457, 9408, 1235, 5075, 11158, 6201, 5966, 4466, 3417, 654, 9814, 2598, 1275, 8232, 3102, 812, 11673, 8142, 5854, 726, 1957, 576, 565, 11777, 2178, 4736, 8675, 5974, 9828, 1047, 3441, 11100, 9205, 11388, 8647, 4869, 9209, 11990, 4329, 10863, 70, 6783, 164, 2008, 9076, 7146, 9848, 3617, 8442, 9078, 1508, 3166, 9914, 10139, 8598, 11504, 7847, 19, 11164, 11023, 5988, 5116, 6580, 2275, 10554, 2194, 4574, 8725, 4120, 4512, 8686, 6391, 3086, 7425, 1346, 2272, 524, 9058, 3100, 8655, 758, 3828, 660, 4111, 7393, 2519, 383, 1580, 3927, 494, 8373, 7389, 8333, 6023, 5413, 7630, 1439, 1650, 2624, 8637, 7978, 9433, 2249, 11236, 5993, 10065, 8319, 6598, 700, 5137, 3609, 10320, 8992, 4422, 7444, 8311, 2905, 1242, 10460, 10374, 1390, 6574, 7964, 7279, 3681, 11794, 3740, 6644, 8710, 8906, 361, 7815, 351, 10425, 4936, 5500, 2074, 8221, 4064, 1948, 4434, 2534, 8667, 5163, 7349, 11286, 5921, 9060, 11594, 2569, 852, 9032, 4346, 8104, 4406, 9658, 207, 6780, 5318, 1577, 2093, 3774, 482, 2199, 11308, 3235, 8201, 2856, 5101, 11982, 7627, 7784, 3013, 9793, 8902, 6489, 9986, 11087, 6584, 530, 7687, 3610, 37, 11166, 7768, 5262, 2923, 6790, 3000, 6276, 8625, 11203, 10515, 6918, 7884, 5832, 1989, 7585, 2944, 1215, 5431, 9526, 4890, 6637, 9086, 9895, 4147, 9785, 3197, 2054, 4763, 4913, 5242, 9462, 6630, 8367, 2175, 7586, 1075, 7578, 9951, 10717, 11817, 11106, 6250, 4796, 3154, 6492, 8037, 1460, 2721, 6567, 6316, 1093, 4659, 5923, 8511, 521, 8365, 4067, 1132, 583, 1425, 9424, 11355, 1083, 7452, 7983, 7, 7864, 11740, 11595, 513, 6362, 8317, 3142, 11226, 5853, 2795, 8717, 7261, 11829, 10446, 146, 10518, 6932, 11101, 6772, 1292, 3872, 9195, 1884, 11384, 6806, 7282, 7879, 7669, 8258, 5239, 9146, 6716, 11599, 1815, 1574, 5448, 10149, 8261, 7000, 9479, 10083, 3824, 2030, 9722, 6588, 11712, 3830, 9689, 10031, 3079, 5678, 712, 7364, 9409, 6115, 1085, 7649, 29, 7451, 5456, 4364, 6288, 1961, 2833, 6450, 9003, 6331, 10874, 11775, 8969, 2847, 4546, 10915, 9391, 3768, 796, 4156, 4168, 4427, 8209, 9150, 11222, 11243, 7744, 2145, 10844, 1308, 2693, 9281, 10798, 4807, 3490, 8369, 3626, 95, 4860, 59, 1216, 10942, 3061, 4436, 10549, 2705, 4871, 11117, 3660, 727, 10214, 9843, 3109, 6727, 4903, 396, 9810, 9686, 5934, 9750, 534, 7465, 2294, 8082, 3903, 10359, 980, 4687, 1129, 7469, 5416, 815, 10449, 9127, 10192, 11490, 7250, 5866, 3880, 4782, 7343, 11154, 5892, 9120, 1709, 340, 735, 6177, 10875, 8943, 7259, 9388, 2517, 11786, 2521, 10092, 10904, 11761, 693, 4806, 5756, 4266, 2105, 1466, 2699, 4714, 752, 7214, 6395, 10814, 11878, 337, 5639, 799, 2297, 5574, 1631, 8956, 7340, 4065, 1353, 2887, 6926, 6068, 8281, 5053, 4092, 417, 8475, 6577, 1155, 7781, 11246, 1799, 10723, 11513, 1853, 8829, 11796, 9759, 5743, 1135, 1506, 3604, 8325, 7852, 5012, 11994, 545, 3934, 5779, 11846, 9628, 11079, 408, 1169, 9098, 8004, 841, 7723, 3420, 2578, 1487, 3248, 11733, 4431, 3127, 1071, 2810, 6030, 7267, 11016, 7439, 7973, 8659, 1543, 8669, 11000, 9068, 8003, 8117, 1296, 120, 2116, 10645, 6111, 6314, 9417, 5093, 9109, 9657, 237, 580, 3671, 4895, 6353, 10543, 11847, 7977, 1870, 3516, 4539, 3608, 1110, 11356, 7510, 9199, 1905, 8459, 10255, 9322, 9704, 11227, 10067, 10292, 7199, 1980, 10812, 4047, 7033, 4068, 5911, 9272, 2466, 5951, 6599, 1665, 8170, 5675, 2704, 6266, 9089, 5105, 9035, 9847, 6290, 11247, 3173, 1655, 4056, 2849, 1077, 2872, 5139, 1949, 11155, 11367, 6167, 9764, 9394, 2480, 4656, 3350, 3700, 4759, 11420, 9053, 2553, 6025, 6648, 3710, 1464, 11769, 6292, 40, 4994, 3533, 8386, 8071, 1028, 10492, 2955, 8891, 7553, 10753, 11607, 10817, 3812, 6157, 10317, 5087, 5089, 3, 2564, 11765, 11037, 10472, 1173, 4836, 9937, 5248, 11921, 4642, 10199, 2239, 2655, 1140, 9476, 9143, 906, 8255, 10183, 4073, 5660, 7860, 8267, 5891, 6103, 585, 6810, 26, 5703, 11113, 11631, 3720, 1767, 437, 5920, 4144, 2520, 8948, 5907, 6043, 2794, 9228, 8138, 11634, 6124, 5835, 11856, 2593, 3974, 5258, 7916, 10913, 3713, 11077, 2068, 4765, 4751, 2, 10572, 8744, 5328, 3787, 4897, 5022, 6310, 2875, 7792, 134, 10624, 3810, 7690, 3531, 9372, 9993, 9959, 2692, 8757, 6825, 8257, 9887, 2836, 11078, 7908, 11469, 619, 11130, 4764, 11373, 4828, 11548, 6622, 2450, 11646, 3435, 7051, 2772, 9875, 5488, 7710, 8919, 9371, 5954, 2943, 4472, 10193, 6138, 3444, 10331, 4540, 1389, 11067, 7007, 9978, 4036, 11701, 2392, 6901, 8731, 3936, 6960, 1536, 7657, 7102, 7572, 330, 5250, 2863, 10025, 1486, 11310, 10066, 10271, 297, 3478, 9024, 4894, 4550, 1313, 8196, 2668, 5402, 2007, 10191, 5417, 1376, 11824, 11978 };
	int size = (int)(*(&number_array + 1) - number_array);

	merge_sort(number_array, size);


	for (int i = 0; i < size; i++) {
		std::cout << number_array[i] << std::endl;
	}

}
