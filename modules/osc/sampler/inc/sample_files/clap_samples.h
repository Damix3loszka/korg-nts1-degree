#include "stdint.h"
#define CLAP_SAMPLES_COUNT 5136
#define CLAP_MIN_SAMPLE -0.3191893696784973
#define CLAP_ATTENUATION_FACTOR 1
uint16_t clap_samples[CLAP_SAMPLES_COUNT] = {
19439, 16083, 22860, 24039, 14526, 18217, 35788, 27569, 19204, 19116, 21670, 33514, 41689, 29275, 17828, 31530, 34949, 43118, 29179, 19644, 25894, 17979, 18587, 20196, 18823, 33103, 28516, 24875, 39116, 29226, 18545, 17940, 19472, 20077, 21297, 21030, 21441, 21103, 21138, 21085, 21062, 21405, 21287, 21519, 21448, 21075, 24788, 23990, 18872, 24565, 24603, 19700, 23662, 24657, 21163, 21100, 22276, 25945, 20559, 20834, 20919, 20227, 21144, 20592, 24468, 19789, 20146, 18362, 22728, 23272, 20271, 19643, 19404, 20851, 25657, 24647, 19289, 22320, 19685, 23116, 21150, 21333, 25467, 20762, 20046, 21107, 20638, 20842, 21011, 20687, 20857, 20617, 20815, 20840, 20353, 26382, 24212, 18114, 22206, 17595, 25603, 37289, 29238, 23695, 20674, 18544, 18398, 19656, 19928, 20342, 20584, 20378, 20355, 20203, 20405, 20495, 20697, 20479, 20617, 20419, 20399, 20380, 20220, 20280, 20241, 20366, 20375, 20480, 20259, 20518, 20386, 20472, 20015, 19042, 19736, 22227, 22822, 19959, 22042, 20979, 20833, 21137, 20211, 20786, 19811, 19738, 17688, 19962, 20402, 21171, 24043, 22206, 20073, 12691, 12857, 12331, 12857, 13114, 19206, 21557, 16523, 23717, 16810, 24066, 21263, 18238, 24181, 16417, 25261, 26050, 20780, 19491, 23312, 26898, 24025, 14365, 15949, 29093, 20491, 21620, 31098, 33687, 28899, 26194, 26909, 21079, 26214, 30504, 25963, 25305, 30576, 30186, 31659, 32142, 33284, 32310, 28857, 26351, 24194, 23471, 20542, 18064, 15450, 17721, 20482, 22002, 22492, 24445, 26303, 24773, 24736, 27120, 24838, 19992, 16171, 14426, 17465, 22664, 28553, 23487, 16822, 16162, 13235, 10187, 8576, 6618, 5600, 6172, 5198, 3224, 2178, 4413, 3855, 6243, 10820, 19240, 25118, 29122, 27159, 27026, 18250, 4805, 15722, 20634, 8801, 3642, 6142, 8257, 8041, 7867, 16318, 23493, 18552, 13099, 24487, 12317, 12527, 5070, 6445, 16903, 19915, 15141, 2829, 6752, 12236, 23259, 20521, 21734, 21638, 28564, 25396, 26402, 15163, 16983, 18435, 27918, 24910, 22940, 20871, 20304, 24100, 14420, 35889, 21856, 25464, 22968, 27305, 35137, 35905, 31192, 11847, 29916, 25763, 22578, 34044, 28305, 33325, 23271, 26026, 30190, 15748, 22024, 17930, 35203, 30647, 20527, 33404, 31038, 25406, 27198, 29054, 18622, 27177, 19715, 13260, 15264, 16074, 11575, 24285, 25082, 17004, 27457, 16111, 16637, 26505, 22023, 26091, 16783, 13948, 14132, 11124, 25451, 15208, 24597, 16907, 16410, 15320, 17162, 16030, 4247, 9788, 7345, 19807, 18412, 13850, 22740, 15521, 10103, 20901, 12386, 24908, 19179, 9533, 10987, 4162, 15562, 25981, 25223, 25159, 16426, 20315, 21113, 13031, 22163, 9782, 14652, 11059, 10159, 16940, 17341, 23159, 18914, 14526, 24004, 20709, 23078, 27526, 30649, 29459, 22913, 21509, 15031, 30227, 22189, 22922, 29631, 21667, 24943, 29923, 31490, 38565, 21543, 19411, 23966, 25523, 28926, 27150, 30247, 22729, 27323, 17260, 21179, 14371, 13501, 19423, 21289, 31232, 28742, 35806, 32537, 31753, 28110, 24904, 27949, 21291, 24293, 24099, 20354, 25437, 20877, 22246, 21282, 14082, 18266, 11494, 13102, 21305, 17809, 25339, 20485, 22371, 36575, 21210, 27740, 24415, 18780, 23189, 21025, 14625, 2708, 12471, 12363, 153, 0, 11971, 10820, 23948, 26306, 28165, 34248, 38749, 37397, 32052, 27290, 26160, 21392, 13273, 29552, 29230, 22275, 19056, 31408, 22666, 26181, 36850, 34922, 32575, 20022, 23126, 29512, 33747, 25740, 14360, 15590, 16294, 21356, 25372, 13924, 18801, 29194, 28992, 25914, 26162, 19971, 16334, 20053, 24576, 23888, 23986, 24797, 18202, 15374, 16257, 13291, 11920, 13047, 6954, 12514, 28878, 33421, 25114, 30785, 36924, 27290, 13960, 24200, 30166, 14442, 17533, 22406, 23663, 17992, 23336, 24594, 25249, 37984, 31695, 29637, 23035, 17715, 16369, 15341, 15031, 17588, 14256, 9368, 10603, 6350, 14783, 27537, 24466, 16408, 24358, 22952, 7430, 11862, 10290, 10251, 17272, 3623, 14423, 25951, 18725, 14642, 15022, 13294, 7015, 6979, 20240, 22740, 19037, 14024, 14848, 22592, 30846, 34234, 25872, 35683, 35619, 31747, 22416, 29473, 25240, 19645, 21945, 11277, 15659, 17083, 31405, 37975, 31492, 30136, 36005, 39957, 47411, 48159, 43524, 31553, 23394, 33545, 36324, 25045, 16393, 16577, 20728, 27512, 22748, 19822, 17045, 16421, 13394, 7447, 5548, 11760, 16433, 15648, 12894, 16716, 21285, 16382, 15427, 22037, 28728, 25567, 24355, 16793, 12226, 14561, 22398, 19472, 6485, 9903, 16631, 9683, 18254, 19088, 9596, 16191, 26177, 27864, 19582, 18376, 10806, 14133, 22562, 26994, 22381, 8859, 10173, 25628, 27033, 24919, 26841, 30728, 34467, 29734, 22555, 15187, 15855, 22296, 26587, 24351, 29229, 30213, 30994, 26636, 23951, 25064, 21004, 15769, 18820, 27240, 22767, 18538, 12749, 11416, 16773, 27881, 33576, 34255, 33200, 28252, 26673, 29691, 28733, 18726, 12905, 13830, 20689, 27897, 34434, 31614, 26101, 21182, 19572, 23106, 22932, 20841, 19817, 18023, 23865, 24038, 13739, 17867, 30591, 27289, 15798, 12064, 10061, 21153, 13930, 14208, 17096, 2036, 5073, 17059, 19908, 16291, 18172, 24629, 28615, 21950, 30398, 39008, 34272, 23716, 20056, 29439, 26332, 26842, 21219, 7642, 8291, 4121, 4525, 10564, 7769, 4686, 2432, 8147, 23396, 33217, 26190, 22342, 30855, 28690, 30597, 22156, 18830, 23432, 22116, 22910, 16977, 13115, 7855, 13048, 14074, 14193, 16616, 13998, 8865, 7138, 16621, 22947, 25426, 27584, 27557, 22776, 19964, 19127, 20842, 23726, 20236, 18036, 17737, 20413, 23735, 27785, 26170, 23899, 26793, 27677, 30280, 30756, 31382, 33296, 31159, 29648, 27284, 23746, 21902, 18416, 17917, 18400, 14376, 9855, 5612, 6178, 8184, 11415, 22881, 23473, 26450, 26072, 22384, 16572, 13660, 21665, 26130, 30090, 24982, 19514, 13886, 6955, 4509, 8902, 15333, 23281, 19063, 14652, 11732, 11174, 11344, 9255, 19289, 26010, 32333, 34152, 26170, 19434, 23220, 22795, 28138, 33754, 27290, 25208, 20288, 17974, 21731, 24638, 22687, 20373, 21789, 24473, 23767, 19523, 15922, 11346, 13945, 17134, 25389, 28566, 21956, 22935, 23201, 24577, 25778, 28077, 30470, 28616, 26161, 24826, 20949, 16977, 17647, 19395, 22747, 26482, 25866, 23456, 20246, 15424, 16360, 19554, 23583, 28586, 31177, 34651, 33763, 32209, 29743, 26895, 24974, 24564, 26902, 26755, 27412, 25120, 19250, 14379, 9003, 9460, 14786, 17654, 23936, 24334, 23537, 27719, 27183, 22614, 24603, 25727, 23642, 25305, 23445, 21870, 22186, 23097, 22855, 20259, 13445, 17449, 24064, 24008, 24270, 27226, 27111, 23420, 17513, 12765, 14974, 14417, 12984, 13201, 16092, 17199, 20780, 22454, 17434, 15957, 18870, 19009, 22005, 23858, 28642, 30520, 30497, 33088, 30428, 30935, 29579, 28019, 25410, 19502, 16340, 18172, 21546, 25490, 21952, 22242, 22865, 22119, 21718, 17959, 16748, 13748, 13917, 15511, 17627, 18752, 19365, 18258, 19050, 21044, 19973, 18519, 16913, 16763, 18862, 21535, 25323, 29477, 31825, 31568, 29600, 26974, 23832, 22216, 17247, 15782, 17737, 17956, 20046, 21118, 18922, 15293, 18772, 21727, 21799, 22443, 22708, 23985, 23737, 27109, 28607, 23625, 22541, 19829, 15505, 13787, 12108, 12368, 10811, 14860, 18588, 14445, 12627, 12582, 14904, 17320, 12546, 10483, 10853, 15132, 22516, 21668, 23027, 26398, 27639, 27340, 27166, 26474, 19895, 16618, 15646, 17690, 21906, 22717, 21872, 19254, 21473, 28479, 30842, 32322, 30033, 18210, 19720, 21123, 14718, 13658, 13736, 23366, 23440, 18179, 26168, 32427, 29727, 20027, 19192, 23843, 20971, 15173, 13154, 13430, 17148, 22624, 21295, 16728, 15727, 19966, 23790, 24932, 23744, 19634, 13331, 14215, 19432, 15608, 11659, 12553, 13439, 22955, 20503, 16780, 27990, 27812, 27733, 22039, 15671, 20057, 17639, 11023, 11185, 14089, 21132, 23334, 18181, 16143, 16679, 20997, 20423, 19840, 16195, 13377, 10367, 10074, 12659, 14396, 20112, 23108, 25000, 25379, 30813, 35342, 31069, 29860, 25013, 18375, 14978, 10060, 12521, 13226, 12777, 13118, 16401, 23637, 29552, 28946, 26002, 27807, 25540, 16125, 10660, 11461, 11234, 13017, 12772, 13803, 21763, 27288, 29461, 29758, 29607, 28653, 23672, 18620, 13555, 12241, 12707, 13411, 15425, 18000, 19124, 23393, 27822, 28141, 30176, 28660, 26374, 26131, 22665, 18652, 17939, 17638, 15393, 15866, 17527, 16787, 17933, 19870, 21572, 21264, 21264, 20359, 18261, 19565, 17389, 13957, 11425, 9608, 10958, 14322, 17768, 20125, 22441, 19956, 21915, 25675, 24754, 23548, 22148, 21907, 20146, 23009, 23385, 15843, 17104, 20354, 20680, 19832, 19629, 24128, 22453, 20234, 17507, 17218, 15765, 17376, 21303, 21984, 22342, 17631, 17519, 17290, 17700, 18336, 16719, 17077, 23086, 25501, 27444, 30577, 28098, 21008, 18088, 20894, 15026, 17756, 24903, 26486, 26720, 21099, 18886, 16928, 14987, 18924, 21817, 22483, 21952, 24092, 24295, 24840, 24965, 23555, 23051, 23766, 23424, 20416, 17917, 16048, 15797, 15269, 15220, 15176, 17282, 20924, 24192, 23270, 22681, 21583, 25314, 27441, 22138, 17992, 18789, 21930, 18063, 11534, 13011, 16872, 19221, 21161, 20948, 22815, 24668, 28693, 28807, 28901, 26936, 23932, 20879, 18886, 17472, 14426, 11411, 10524, 11498, 12125, 14997, 14473, 15756, 17304, 21962, 26153, 28849, 28313, 27846, 26337, 25158, 28502, 26685, 23946, 25653, 27705, 25928, 24651, 21287, 18969, 16996, 19633, 21113, 17922, 18933, 17802, 19198, 18844, 15624, 17959, 19491, 17891, 19627, 20352, 21562, 24880, 25620, 27960, 28913, 29115, 29737, 29927, 29423, 28220, 24695, 21877, 18359, 14992, 15258, 13201, 11615, 13951, 16980, 22044, 24660, 24541, 27448, 26670, 25081, 22207, 18905, 17868, 16804, 17560, 18271, 20258, 22740, 23043, 24655, 26451, 26683, 25522, 22757, 20664, 20036, 18280, 18071, 18732, 19973, 21556, 21900, 20573, 19205, 21173, 20215, 20304, 20266, 18064, 20355, 20152, 18370, 20117, 19246, 20518, 23824, 24961, 25780, 25635, 23292, 20372, 23808, 26539, 24634, 23263, 20738, 20451, 20254, 16963, 15647, 16383, 18060, 17348, 16937, 20440, 20446, 20978, 22790, 23589, 21769, 21646, 22537, 22638, 25726, 25638, 25112, 21393, 20340, 20187, 17939, 18819, 20845, 22778, 23296, 20558, 19455, 20364, 19998, 21037, 21067, 21389, 20284, 18848, 16789, 15558, 15944, 16833, 18143, 20789, 22283, 22219, 23105, 23682, 24206, 25502, 26456, 25294, 23173, 21212, 20479, 19734, 20017, 20135, 19806, 19657, 19089, 17256, 16207, 15106, 14852, 15636, 17421, 20427, 22458, 25700, 28173, 27500, 25777, 25169, 23541, 21095, 19963, 16149, 13839, 14991, 14247, 14070, 16481, 18883, 20532, 23254, 23539, 23692, 26211, 25175, 20912, 19089, 19865, 20314, 20974, 20399, 18735, 19776, 15914, 15908, 19402, 22134, 24633, 23206, 22981, 24086, 22458, 20510, 22479, 22834, 25598, 23783, 20933, 17618, 12511, 13964, 15945, 17201, 19020, 20161, 24311, 26186, 24452, 23528, 21376, 20569, 20186, 21077, 20025, 18881, 19496, 19912, 21132, 21702, 21739, 21928, 20674, 20233, 19344, 18664, 18965, 19301, 20458, 20053, 21741, 22081, 24012, 25246, 24879, 25930, 24774, 22481, 20124, 19033, 17839, 16921, 16142, 16365, 17968, 20334, 21579, 21737, 21847, 21909, 20641, 20686, 20889, 19759, 19960, 19053, 18155, 19017, 20176, 20909, 22892, 21423, 22298, 23520, 20678, 21266, 19850, 19652, 20313, 21338, 20659, 21448, 23418, 22178, 21440, 19958, 20680, 20050, 18144, 16734, 16554, 15819, 17149, 18159, 18406, 20209, 21683, 23970, 25320, 25480, 25599, 26094, 24842, 23214, 20869, 20513, 19644, 20052, 20458, 20033, 18656, 16927, 20196, 21419, 22390, 22729, 23003, 23616, 23630, 22035, 19760, 19648, 18701, 18813, 18691, 18906, 19459, 18749, 19504, 20805, 22285, 22753, 22792, 24026, 24177, 24523, 24509, 23197, 21076, 19624, 18533, 17893, 17680, 17196, 17306, 17885, 18065, 18416, 20346, 22006, 24036, 24208, 24767, 24608, 23864, 23342, 22832, 21048, 18172, 17992, 17910, 18646, 18576, 19377, 20844, 20592, 19075, 17897, 16999, 19846, 19916, 19285, 20052, 20318, 20752, 21427, 23433, 24330, 25240, 22520, 21224, 19849, 20986, 22495, 22626, 22467, 21758, 21666, 21374, 21467, 21400, 20538, 18987, 18514, 19868, 21438, 21513, 21262, 20221, 19657, 19605, 20689, 20803, 21288, 21985, 24735, 24656, 23320, 23160, 21911, 21045, 20128, 21237, 20453, 19969, 19741, 20329, 20485, 20326, 20761, 20615, 21134, 20799, 20151, 19151, 18541, 20358, 22310, 22431, 22600, 22352, 21282, 21196, 21929, 21482, 20935, 21231, 22280, 22601, 23636, 24805, 25692, 25981, 24111, 22594, 20905, 20156, 19837, 19589, 18306, 17908, 16923, 16869, 17047, 17232, 19701, 20107, 20774, 21496, 21794, 22754, 23829, 23780, 22964, 22962, 22960, 22574, 22420, 21039, 20829, 20791, 20292, 19768, 20473, 20190, 19715, 18564, 18491, 20009, 20717, 21926, 21396, 22616, 22654, 22077, 23033, 23897, 23915, 22587, 21729, 20854, 19291, 20340, 21317, 22700, 23738, 24362, 24630, 23641, 22873, 21472, 20324, 19377, 18822, 18157, 17622, 17161, 17213, 18438, 20430, 21694, 22774, 23226, 23476, 23633, 22568, 22257, 22102, 21462, 20250, 18295, 19364, 20181, 20339, 20751, 21055, 21743, 22950, 23638, 23249, 23313, 22578, 21761, 21846, 20710, 18661, 17067, 15880, 16711, 17155, 18468, 19238, 19538, 20551, 21768, 22667, 23742, 23011, 22831, 22399, 20242, 21844, 23417, 23797, 22800, 22112, 20759, 20082, 18688, 18048, 19568, 19557, 20250, 19616, 18692, 18449, 18007, 19112, 20250, 21498, 21520, 21930, 22552, 20713, 20491, 20400, 21968, 23041, 23113, 22371, 21362, 21433, 20988, 21244, 21263, 20509, 19652, 20130, 19298, 18639, 18561, 18702, 18467, 18728, 19604, 19812, 20541, 21627, 22667, 22987, 23185, 23545, 23914, 23361, 23153, 22709, 21633, 20567, 20017, 19486, 18799, 18144, 17891, 17877, 17892, 18107, 18996, 20724, 21907, 22536, 23059, 23388, 23284, 23989, 22714, 20950, 20624, 20290, 19322, 19259, 19467, 18816, 18443, 17711, 19464, 20543, 20956, 21732, 21662, 22648, 22997, 22333, 20511, 19409, 18707, 18989, 19037, 18666, 18085, 17789, 18468, 19239, 20828, 21456, 23063, 23815, 24487, 23104, 21796, 21198, 21048, 21005, 20556, 19967, 18570, 19774, 20686, 20879, 19917, 20396, 21747, 21744, 19871, 18955, 19452, 20099, 20692, 21041, 20923, 20408, 21341, 21954, 22734, 22915, 23848, 24268, 22742, 21648, 20991, 20897, 20309, 19648, 18470, 19141, 19933, 20048, 20326, 19764, 21126, 20538, 19004, 18473, 18625, 19391, 19751, 20410, 20624, 21514, 22756, 23163, 23182, 23378, 23523, 22693, 21479, 20610, 20154, 20208, 19861, 18364, 18806, 19970, 20077, 19792, 20193, 21059, 21325, 20079, 18494, 18548, 19114, 19950, 20687, 21780, 21638, 22603, 23345, 23782, 23412, 22459, 22733, 22478, 21962, 20616, 19857, 19498, 20194, 19658, 19509, 19509, 18626, 19528, 19448, 19056, 19047, 19240, 19524, 20900, 21537, 20384, 21018, 22337, 22678, 22967, 22646, 21724, 20198, 20374, 22005, 22015, 22282, 22129, 21775, 21263, 21050, 20551, 19510, 19005, 18899, 19169, 19420, 19549, 19857, 19925, 20124, 20239, 20710, 21743, 22094, 23417, 23465, 23486, 24018, 23560, 23779, 22340, 20483, 20380, 19943, 20043, 20006, 19853, 19835, 19697, 19347, 18681, 18492, 19327, 20428, 20728, 20774, 20463, 20613, 20911, 21943, 22546, 23599, 23419, 22077, 22093, 21693, 21593, 21311, 21275, 20411, 20004, 19872, 19629, 19041, 18588, 18549, 18779, 20456, 20576, 21472, 21309, 20833, 21034, 21091, 21541, 21476, 22267, 23173, 23301, 22306, 22257, 21876, 21846, 21498, 20859, 21363, 21123, 20930, 20546, 20415, 20550, 20294, 20587, 19863, 19388, 19614, 19275, 20809, 22033, 21904, 21521, 21328, 21188, 21308, 21523, 21837, 22485, 22653, 22166, 22060, 22476, 23166, 23567, 22290, 21338, 20822, 20127, 19817, 19985, 19750, 19965, 19787, 19806, 20566, 20801, 20999, 20710, 20310, 20096, 20520, 20543, 20764, 21306, 22204, 22828, 22883, 22871, 23236, 23327, 22499, 21603, 20769, 20283, 19894, 21053, 21822, 21847, 21686, 21148, 20734, 20617, 20312, 19807, 20368, 20602, 20500, 20654, 20828, 20959, 21261, 21310, 21571, 21892, 22450, 22177, 22110, 23288, 22369, 21785, 21337, 20923, 20626, 20020, 20228, 19725, 20240, 20695, 20988, 21352, 21040, 20768, 20893, 20582, 20174, 20063, 20249, 20403, 20419, 21040, 20829, 21227, 21608, 22387, 23142, 22984, 23210, 22883, 22200, 21381, 20924, 20883, 20946, 21180, 20966, 20953, 21320, 20805, 19678, 19528, 19475, 19563, 19829, 19852, 19775, 19911, 20564, 21085, 21582, 21721, 21980, 22031, 21894, 21092, 21663, 22583, 22427, 22238, 21738, 21450, 21074, 20794, 20732, 20449, 20598, 20945, 20023, 19520, 19430, 19547, 19538, 19546, 19819, 20174, 20318, 20506, 20764, 20818, 20511, 20731, 21477, 21773, 23166, 23300, 22791, 22408, 21803, 21297, 21429, 21236, 20071, 19844, 19604, 19239, 19220, 19510, 19378, 19498, 19372, 19681, 19804, 19951, 21121, 21348, 21852, 22111, 22016, 22566, 22905, 23144, 22709, 21506, 20786, 20476, 20333, 20019, 19764, 19549, 19366, 18771, 18647, 19565, 20263, 21085, 21245, 21371, 21644, 21945, 22250, 21505, 20778, 20597, 20474, 20618, 20885, 20575, 20312, 19632, 20026, 20976, 21689, 22288, 22358, 22178, 22033, 22363, 21557, 20763, 20222, 19579, 19312, 19081, 18828, 18737, 18700, 19547, 20439, 21169, 21532, 21816, 22222, 22824, 22273, 21117, 21063, 21316, 21729, 21571, 21174, 20055, 20011, 20496, 20542, 20424, 20075, 20223, 20854, 20231, 19615, 19615, 19660, 20176, 20353, 20482, 20353, 21070, 21432, 21641, 22095, 22204, 23169, 22334, 21144, 20734, 20191, 20018, 20260, 20360, 20165, 21012, 21319, 21518, 20864, 21091, 21455, 20414, 19944, 19404, 19250, 19528, 19709, 19540, 20509, 21387, 21889, 22579, 22834, 23044, 22445, 21505, 20912, 20744, 20605, 20625, 20050, 19691, 20165, 20569, 20706, 20779, 20918, 21266, 20889, 20166, 20127, 20085, 20485, 20696, 20738, 20310, 20798, 21605, 21806, 21795, 21521, 21576, 21881, 21535, 20951, 21026, 20719, 20900, 21123, 21092, 20575, 20265, 20597, 20472, 20297, 20071, 19999, 20402, 21289, 21255, 20700, 20475, 20561, 20817, 20787, 20794, 20663, 20420, 20897, 21826, 21910, 22149, 22130, 22020, 21726, 21663, 21368, 20362, 19868, 19507, 19688, 19720, 20013, 20076, 19989, 19680, 19564, 20336, 21071, 21603, 22184, 22287, 22213, 22099, 22302, 22011, 20928, 20667, 20279, 20436, 20578, 20889, 21114, 21214, 21077, 20756, 20140, 20214, 20692, 20646, 20328, 19992, 20204, 20209, 20743, 21190, 22039, 21688, 21403, 21214, 20909, 21136, 21180, 21240, 21146, 20935, 20864, 20841, 20536, 20048, 19745, 20507, 20851, 21039, 21013, 21077, 21051, 20942, 20836, 20879, 20858, 21237, 21159, 20521, 20622, 20805, 21104, 21150, 21389, 21430, 21192, 20956, 20721, 20580, 20524, 20522, 20639, 20571, 20465, 20232, 20939, 21345, 21277, 21447, 21165, 21161, 21051, 21001, 20725, 20362, 20219, 20474, 20912, 21746, 22212, 21650, 21000, 20677, 20666, 20925, 21223, 21095, 20864, 20553, 20384, 20255, 20423, 20905, 21158, 21248, 21217, 21107, 20792, 20562, 20294, 20290, 20828, 20951, 20840, 20695, 20671, 20644, 20943, 21775, 22210, 22352, 22110, 21856, 21667, 21456, 21176, 20893, 20605, 20401, 20358, 20452, 20635, 20890, 20963, 20854, 20730, 20602, 20692, 20831, 20812, 20962, 21416, 21069, 20884, 21007, 21173, 21460, 21531, 21485, 21248, 20921, 20615, 20609, 20811, 20896, 20793, 20589, 20472, 20702, 20843, 20943, 21091, 21200, 21093, 21008, 20852, 20667, 20595, 20183, 20431, 21220, 21633, 21713, 21517, 21375, 21391, 21461, 21339, 21278, 21391, 21239, 21175, 20927, 21210, 21268, 20712, 20589, 20372, 20262, 20074, 20029, 20091, 20365, 20831, 21087, 21198, 21280, 21444, 21455, 21299, 21327, 20969, 21093, 21569, 21512, 21445, 21087, 20779, 20678, 20761, 20803, 20871, 20995, 21334, 21015, 20577, 20518, 20395, 20409, 20345, 20434, 20494, 20689, 20840, 21026, 21157, 21175, 20961, 21084, 21502, 21527, 21403, 21115, 20957, 20747, 20639, 20681, 21178, 21346, 21029, 20959, 20698, 20368, 20054, 20166, 20361, 20494, 20428, 20428, 20324, 20361, 21050, 21510, 21686, 21589, 21414, 21300, 21077, 21107, 21195, 20888, 20680, 20495, 20449, 20426, 20301, 20179, 20142, 20265, 20211, 20319, 20804, 21022, 21267, 21272, 21284, 21412, 21593, 21636, 20933, 20734, 20556, 20611, 20821, 20974, 20845, 20767, 20530, 20499, 20788, 20717, 20820, 20791, 21002, 21235, 21457, 21089, 20640, 20352, 20245, 20313, 20425, 20584, 20491, 20405, 20800, 21233, 21465, 21565, 21434, 21352, 21458, 21244, 20801, 20737, 20507, 20489, 20468, 20599, 20512, 20586, 20814, 20782, 20788, 20689, 20649, 20919, 20935, 20717, 20883, 20895, 20887, 20947, 21122, 21033, 21234, 21503, 21573, 21466, 21307, 21306, 21185, 20864, 20722, 20677, 20368, 20206, 20020, 19969, 20328, 20750, 20921, 21187, 21267, 21652, 21551, 21052, 20951, 20804, 20948, 21043, 20879, 20917, 21119, 21065, 21216, 21222, 21419, 21382, 20858, 20537, 20277, 20221, 20324, 20368, 20221, 20508, 20907, 21145, 21275, 21215, 21463, 21379, 20815, 20669, 20654, 20793, 21002, 21125, 20988, 21043, 21420, 21477, 21477, 21325, 21339, 21361, 21075, 20616, 20422, 20291, 20341, 20331, 20236, 20123, 19973, 20348, 20645, 20998, 21258, 21442, 21564, 21790, 21605, 21193, 21148, 21137, 21210, 21133, 20954, 20638, 20296, 20331, 20720, 20795, 20701, 20565, 20625, 20716, 21086, 21192, 20943, 20922, 20746, 20644, 20487, 20541, 20699, 20756, 20547, 20536, 20927, 21197, 21442, 21578, 21536, 21538, 21480, 21514, 21262, 20885, 20667, 20489, 20423, 20412, 20449, 20532, 20520, 20386, 20236, 20191, 20500, 20644, 20874, 21018, 21077, 21221, 21390, 21542, 21732, 21719, 21468, 21320, 21132, 20949, 20725, 20483, 20225, 20143, 20220, 20352, 20378, 20251, 20318, 20695, 20987, 21261, 21469, 21633, 21723, 21692, 21700, 21424, 21119, 21083, 20850, 20618, 20644, 20874, 20986, 20956, 21002, 20951, 20944, 20820, 20660, 20555, 20523, 20404, 20327, 20307, 20411, 20720, 20791, 20821, 20904, 20927, 20905, 20915, 21039, 20991, 20695, 20938, 21388, 21402, 21496, 21309, 21158, 21088, 20984, 21043, 21087, 20718, 20147, 20397, 20429, 20396, 20255, 20371, 20564, 20778, 20905, 20777, 20962, 21065, 21261, 21291, 21129, 20977, 20882, 20702, 20902, 20753, 21133, 21252, 21221, 21204, 21200, 21263, 21160, 21077, 20681, 21031, 20925, 20875, 20787, 20897, 20895, 20815, 20844, 20448, 20661, 20824, 21010, 21165, 20713, 20787, 20718, 20831, 21175, 20743, 20806, 20854, 21381, 21558, 21275, 21412, 21206, 20711, 20477, 20597, 20383, 20593, 20578, 20415, 20512, 20690, 20647, 21004, 21275, 21107, 21249, 20909, 20602, 20695, 20877, 21122, 21028, 20801, 20752, 20658, 21084, 21005, 21231, 21303, 21238, 21378, 21246, 21199, 20782, 20639, 20369, 20490, 20498, 20223, 20528, 20666, 20645, 20979, 21030, 21084, 21049, 20740, 20698, 20700, 20918, 21158, 21357, 21305, 21094, 21221, 21157, 20961, 20799, 20611, 20448, 20294, 20261, 20358, 20642, 20895, 21079, 21019, 20895, 20668, 20593, 20921, 21190, 21337, 21293, 21127, 20830, 20827, 20569, 20410, 20601, 20543, 20919, 21123, 21232, 21392, 21156, 21071, 21145, 21184, 21219, 21137, 20868, 20563, 20423, 20347, 20383, 20399, 20406, 20560, 20760, 20969, 21095, 21130, 21217, 21403, 21489, 21523, 21514, 21369, 21237, 21201, 21315, 21467, 21333, 21208, 21053, 20854, 20740, 20651, 20698, 20935, 21014, 21107, 21064, 21065, 21314, 21047, 21037, 21103, 20905, 20985, 21257, 20978, 20595, 20692, 20935, 20729, 20638, 20723, 20708, 20904, 20772, 20809, 20896, 21121, 21078, 20980, 21141, 21381, 21255, 20904, 20991, 20910, 20684, 20677, 21008, 20861, 20684, 20928, 21163, 21131, 20891, 20904, 21083, 21180, 21077, 20685, 20422, 20566, 20736, 20792, 20608, 20625, 20838, 21139, 21306, 21226, 21174, 21148, 21210, 21365, 21348, 21162, 21105, 21114, 21205, 21052, 20663, 20425, 20374, 20345, 20540, 21012, 21314, 21333, 21407, 21459, 21348, 21047, 21169, 21371, 20930, 20699, 20669, 20719, 20638, 20614, 20527, 20657, 21005, 20736, 20734, 20699, 20589, 20735, 20873, 20977, 21184, 21103, 20774, 20662, 20758, 20987, 21053, 20977, 20782, 20882, 20925, 20721, 20712, 20836, 20935, 21145, 21008, 20952, 21256, 21129, 20946, 20738, 20745, 20761, 20507, 20798, 20630, 20452, 20544, 20541, 20674, 20871, 21139, 21087, 21301, 21407, 21386, 21297, 21462, 21232, 21034, 21028, 20747, 20797, 20716, 20761, 20771, 20544, 20471, 20705, 20803, 20915, 21008, 21114, 21087, 20876, 21102, 21324, 21133, 20993, 20959, 21075, 21309, 21378, 21390, 21293, 21101, 20873, 20703, 20603, 20599, 20546, 20521, 20478, 20553, 20689, 20639, 20697, 20955, 21173, 21084, 21130, 20998, 20865, 21012, 21099, 21025, 20756, 20930, 21102, 20787, 20901, 20903, 20634, 20708, 20820, 20896, 20769, 20751, 20690, 20619, 20682, 20870, 20843, 20594, 20591, 20831, 21072, 21159, 21283, 21306, 21271, 21197, 21022, 20768, 20709, 20769, 20798, 20894, 21147, 21339, 21315, 21214, 21052, 20922, 20829, 20798, 20848, 21055, 20962, 20660, 20493, 20432, 20618, 20854, 21055, 21174, 21201, 21205, 21261, 21316, 21270, 20988, 20778, 20784, 20878, 21098, 21281, 21301, 21242, 21158, 21092, 21017, 20933, 20840, 20742, 20680, 20829, 20934, 20635, 20570, 20875, 20958, 20819, 20825, 20858, 21199, 21134, 21141, 21374, 21062, 20885, 20888, 20836, 20713, 20682, 20808, 20964, 20757, 20822, 21073, 21143, 21114, 21040, 21150, 21104, 21097, 20965, 20689, 20820, 20713, 20556, 20658, 20788, 20900, 20975, 21059, 21165, 21349, 21138, 20849, 20885, 20991, 20953, 20859, 20785, 20794, 20752, 20627, 20571, 20627, 20676, 20727, 20734, 20667, 20639, 20552, 20549, 20642, 20817, 20974, 21021, 21030, 21011, 20935, 20870, 20850, 20846, 20857, 20853, 20864, 20884, 20888, 20877, 20890, 20902, 20884, 20963, 21099, 21145, 21145, 21107, 21139, 21179, 21203, 21212, 21138, 21088, 21081, 21059, 20985, 20928, 20909, 20887, 20820, 20691, 20632, 20728, 20658, 20602, 20572, 20536, 20525, 20494, 20719, 21007, 21180, 21114, 20943, 20843, 20834, 20806, 20802, 20880, 21064, 21140, 21079, 21042, 20964, 20852, 20732, 20825, 20981, 21075, 20978, 20781, 20614, 20597, 20646, 20783, 20960, 20881, 20803, 20783, 20747, 20752, 20846, 20860, 20785, 20659, 20751, 20923, 20985, 20935, 20824, 20808, 20876, 21143, 21243, 21090, 20949, 20894, 20924, 20984, 21001, 20994, 20953, 20879, 20836, 20765, 20670, 20680, 20771, 20871, 20958, 21023, 20990, 20913, 20832, 20800, 20870, 20935, 21019, 21087, 21135, 21159, 21170, 21194, 21241, 21230, 21180, 21121, 21026, 20950, 20820, 20712, 20671, 20589, 20611, 20709, 20811, 20962, 21092, 21159, 21183, 21206, 21166, 21237, 21269, 21186, 21097, 21020, 20941, 20839, 20798, 20777, 20782, 20715, 20751, 20832, 20888, 20952, 20959, 20964, 20940, 20824, 20753, 20805, 20969, 21115, 21084, 21082, 21017, 20972, 21044, 21058, 20915, 20799, 20822, 20886, 20968, 21010, 20970, 20936, 20964, 20966, 21008, 21069, 21203, 21218, 21074, 20962, 20903, 20878, 20810, 20736, 20686, 20705, 20768, 20841, 20879, 20937, 21031, 21121, 21158, 21097, 21000, 20902, 20807, 20734, 20685, 20670, 20708, 20771, 20814, 20859, 20931, 20980, 21004, 20994, 20991, 21053, 21064, 21049, 21059, 21042, 21061, 21104, 21110, 21097, 21103, 21094, 21089, 21123, 21133, 21082, 20991, 20923, 20877, 20864, 20897, 20954, 20989, 20980, 20933, 20859, 20814, 20765, 20679, 20599, 20548, 20556, 20622, 20699, 20747, 20729, 20750, 20795, 20766, 20764, 20833, 20904, 20937, 20987, 21035, 21066, 21061, 21039, 21009, 20935, 20872, 20841, 20887, 21005, 21035, 20941, 20796, 20728, 20881, 21038, 21121, 21045, 20719, 20709, 20872, 20783, 20743, 20750, 20989, 21079, 20793, 20821, 20983, 21026, 20796, 20615, 20777, 20911, 20881, 20859, 20898, 20972, 21102, 21033, 20807, 20631, 20601, 20675, 20775, 20853, 20883, 20776, 20846, 21097, 21051, 20852, 20744, 20762, 20939, 20885, 20666, 20807, 20929, 20921, 20786, 20633, 20801, 20948, 20831, 20750, 20780, 20901, 21009, 20930, 20773, 20665, 20716, 20809, 20856, 20805, 20719, 20708, 20737, 20779, 20822, 20894, 21001, 21031, 20994, 21016, 21054, 21031, 20963, 20906, 20858, 20780, 20670, 20633, 20617, 20589, 20597, 20647, 20769, 20969, 21133, 21161, 21175, 21195, 21118, 20933, 20799, 20672, 20616, 20625, 20586, 20681, 20821, 20944, 21032, 21058, 21066, 21029, 20942, 20862, 20806, 20751, 20702, 20705, 20726, 20760, 20854, 20921, 20957, 20993, 21046, 21094, 21145, 21147, 21066, 20983, 20913, 20849, 20830, 20847, 20847, 20870, 20926, 20947, 20921, 20882, 20845, 20838, 20840, 20825, 20803, 20778, 20768, 20787, 20823, 20897, 20992, 21054, 21059, 21039, 21036, 20983, 20924, 20925, 20917, 20882, 20843, 20819, 20826, 20860, 20909, 20958, 21004, 21027, 21022, 21018, 20997, 20963, 20939, 20909, 20925, 20948, 20958, 20965, 20913, 20844, 20760, 20734, 20740, 20806, 20875, 20954, 21003, 21035, 21081, 21051, 20935, 20808, 20828, 20774, 20786, 20972, 21094, 21129, 21095, 20989, 20849, 20710, 20744, 20796, 20800, 20869, 20968, 21080, 21136, 21111, 21074, 21116, 21101, 20983, 20840, 20701, 20584, 20566, 20660, 20740, 20730, 20771, 20902, 21063, 21084, 20982, 20936, 21010, 21046, 20914, 20782, 20782, 20884, 20910, 20824, 20865, 21012, 21101, 21113, 21037, 20985, 20981, 20992, 20971, 20937, 20873, 20807, 20775, 20763, 20770, 20774, 20766, 20743, 20749, 20763, 20756, 20739, 20717, 20742, 20842, 20952, 21049, 21125, 21167, 21162, 21144, 21117, 21075, 21024, 20957, 20911, 20894, 20868, 20850, 20840, 20831, 20841, 20850, 20857, 20843, 20830, 20836, 20810, 20770, 20748, 20766, 20798, 20834, 20897, 20939, 20987, 21045, 21078, 21083, 21067, 21049, 21020, 20995, 20971, 20923, 20873, 20793, 20723, 20719, 20693, 20675, 20738, 20859, 21022, 21098, 21081, 21109, 21098, 21006, 20890, 20800, 20778, 20796, 20811, 20820, 20865, 20907, 20931, 20965, 20994, 20984, 20924, 20873, 20859, 20865, 20879, 20916, 20962, 20999, 21010, 20993, 20965, 20937, 20934, 20947, 20965, 20968, 20953, 20941, 20931, 20918, 20914, 20917, 20911, 20892, 20868, 20859, 20862, 20878, 20899, 20903, 20900, 20908, 20935, 20961, 20978, 20965, 20919, 20870, 20851, 20842, 20841, 20869, 20888, 20896, 20913, 20928, 20945, 20954, 20959, 20960, 20956, 20972, 20969, 20952, 20920, 20881, 20860, 20870, 20891, 20924, 20976, 21013, 21017, 20988, 20965, 20951, 20936, 20909, 20884, 20864, 20838, 20815, 20818, 20842, 20879, 20935, 20987, 20999, 20972, 20937, 20901, 20893, 20899, 20912, 20914, 20898, 20879, 20856, 20861, 20899, 20944, 20966, 20970, 20973, 20937, 20904, 20879, 20837, 20843, 20896, 20959, 21004, 21049, 21084, 21050, 20984, 20928, 20861, 20796, 20741, 20676, 20642, 20659, 20710, 20793, 20905, 20997, 21058, 21113, 21125, 21089, 21018, 20937, 20847, 20770, 20744, 20758, 20812, 20909, 20975, 20968, 20891, 20826, 20827, 20866, 20929, 20962, 20939, 20871, 20806, 20787, 20834, 20904, 20954, 20954, 20911, 20860, 20804, 20768, 20760, 20792, 20865, 20942, 21005, 21044, 21034, 21006, 20955, 20892, 20838, 20799, 20783, 20755, 20719, 20683, 20681, 20713, 20764, 20840, 20907, 20954, 20993, 21015, 21031, 21038, 21031, 21007, 20982, 20959, 20923, 20895, 20878, 20865, 20848, 20842, 20845, 20846, 20841, 20825, 20823, 20831, 20827, 20825, 20840, 20849, 20846, 20856, 20883, 20909, 20921, 20928, 20933, 20938, 20949, 20962, 20966, 20955, 20945, 20935, 20947, 20970, 20972, 20955, 20932, 20907, 20875, 20839, 20797, 20776, 20775, 20780, 20787, 20805, 20837, 20870, 20894, 20915, 20931, 20940, 20948, 20949, 20951, 20957, 20962, 20955, 20954, 20954, 20953, 20955, 20940, 20916, 20900, 20895, 20907, 20924, 20941, 20952, 20946, 20927, 20921, 20922, 20932, 20938, 20946, 20963, 20967, 20952, 20919, 20895, 20878, 20876, 20881, 20885, 20882, 20885, 20898, 20911, 20933, 20959, 20984, 20981, 20951, 20905, 20865, 20840, 20841, 20857, 20868, 20888, 20915, 20946, 20960, 20969, 20975, 20985, 20999, 20988, 20966, 20940, 20927, 20920, 20919, 20921, 20926, 20925, 20911, 20886, 20864, 20872, 20889, 20903, 20909, 20894, 20867, 20857, 20862, 20883, 20906, 20922, 20930, 20938, 20949, 20960, 20971, 20976, 20976, 20955, 20938, 20923, 20908, 20917, 20929, 20933, 20928, 20909, 20879, 20862, 20834, 20801, 20796, 20811, 20845, 20878, 20909, 20934, 20955, 20968, 20958, 20937, 20922, 20927, 20936, 20945, 20948, 20936, 20927, 20928, 20925, 20917, 20909, 20889, 20869, 20848, 20834, 20830, 20838, 20850, 20855, 20873, 20881, 20884, 20895, 20910, 20937, 20962, 20972, 20963, 20944, 20907, 20878, 20858, 20843, 20847, 20863, 20886, 20896, 20904, 20922, 20948, 20958, 20954, 20936, 20899, 20861, 20837, 20831, 20834, 20844, 20837, 20830, 20840, 20863, 20902, 20932, 20953, 20967, 20970, 20968, 20960, 20959, 20959, 20944, 20923, 20902, 20885, 20884, 20889, 20884, 20879, 20880, 20878, 20873, 20867, 20850, 20842, 20860, 20889, 20913, 20922, 20931, 20946, 20956, 20962, 20968, 20967, 20958, 20934, 20903, 20880, 20867, 20866, 20878, 20904, 20936, 20964, 20968, 20951, 20916, 20874, 20842, 20828, 20826, 20825, 20833, 20849, 20878, 20907, 20943, 20979, 21004, 21013, 21008, 20999, 20977, 20945, 20917, 20895, 20873, 20862, 20858, 20857, 20874, 20903, 20925, 20942, 20955, 20960, 20952, 20942, 20936, 20930, 20927, 20911, 20890, 20882, 20884, 20883, 20884, 20892, 20910, 20925, 20929, 20925, 20920, 20923, 20933, 20945, 20950, 20956, 20954, 20936, 20908, 20886, 20877, 20878, 20879, 20878, 20878, 20889, 20908, 20923, 20937, 20950, 20961, 20960, 20957, 20954, 20936, 20916, 20896, 20877, 20862, 20851, 20858, 20872, 20882, 20885, 20892, 20903, 20918, 20933, 20943, 20940, 20918, 20902, 20891, 20890, 20891, 20896, 20908, 20920, 20920, 20913, 20914, 20917, 20916, 20914, 20912, 20904, 20891, 20880, 20874, 20876, 20882, 20884, 20884, 20884, 20878, 20872, 20872, 20874, 20880, 20887, 20904, 20928, 20945, 20946, 20938, 20930, 20916, 20906, 20897, 20880, 20865, 20861, 20863, 20865, 20874, 20883, 20878, 20876, 20884, 20894, 20901, 20907, 20914, 20916, 20913, 20902, 20896, 20889, 20876, 20868, 20871, 20878, 20878, 20878, 20881, 20891, 20903, 20909, 20910, 20907, 20902, 20894, 20883, 20876, 20870, 20863, 20860, 20856, 20851, 20856, 20870, 20879, 20886, 20896, 20913, 20924, 20922, 20919, 20913, 20910, 20911, 20909, 20900, 20899, 20905, 20906, 20909, 20910, 20912, 20910, 20897, 20886, 20882, 20881, 20880, 20875, 20868, 20870, 20883, 20893, 20895, 20895, 20903, 20907, 20900, 20893, 20890, 20895, 20907, 20914, 20915, 20921, 20926, 20926, 20921, 20915, 20915, 20910, 20900, 20888, 20874, 20868, 20869, 20864, 20869, 20885, 20897, 20905, 20914, 20925, 20934, 20931, 20915, 20903, 20905, 20919, 20924, 20924, 20919, 20918, 20918, 20910, 20903, 20899, 20902, 20901, 20893, 20895, 20907, 20916, 20927, 20931, 20937, 20935, 20922, 20909, 20897, 20894, 20892, 20893, 20894, 20905, 20911, 20907, 20914, 20925, 20932, 20932, 20926, 20916, 20905, 20904, 20915, 20920, 20925, 20926, 20917, 20908, 20903, 20900, 20893, 20894, 20907, 20919, 20929, 20931, 20924, 20917, 20909, 20902, 20903, 20912, 20917, 20918, 20920, 20917, 20913, 20911, 20912, 20910, 20905, 20901, 20900, 20905, 20909, 20913, 20917, 20919, 20919, 20915, 20906, 20904, 20907, 20905, 20904, 20906, 20908, 20906, 20904, 20906, 20911, 20914, 20916, 20919, 20916, 20913, 20907, 20900, 20895, 20895, 20895, 20895, 20895, 20897, 20896, 20897, 20906, 20911, 20914, 20915, 20915, 20915, 20917, 20916, 20919, 20924, 20931, 20934, 20926, 20918, 20909, 20900, 20892, 20890, 20888, 20888, 20887, 20888, 20893, 20900, 20900, 20899, 20901, 20901, 20897, 20893, 20905, 20918, 20923, 20920, 20912, 20904, 20901, 20905, 20906, 20906, 20902, 20899, 20902, 20909, 20918, 20927, 20927, 20920, 20910, 20903, 20894, 20883, 20878, 20883, 20891, 20899, 20909, 20917, 20919, 20919, 20916, 20913, 20914, 20913, 20912, 20914, 20917, 20917, 20917, 20917, 20919, 20917, 20914, 20910, 20904, 20901, 20898, 20907, 20923, 20932, 20934, 20931, 20925, 20921, 20923, 20926, 20926, 20923, 20920, 20913, 20903, 20899, 20904, 20912, 20921, 20927, 20929, 20928, 20926, 20929, 20929, 20927, 20924, 20919, 20916, 20915, 20916, 20914, 20915, 20920, 20924, 20925, 20921, 20914, 20911, 20913, 20918, 20927, 20938, 20947, 20950, 20950, 20946, 20941, 20935, 20932, 20929, 20925, 20924, 20925, 20927, 20929, 20929, 20929, 20930, 20935, 20939, 20942, 20948, 20945, 20937, 20929, 20924, 20923, 20922, 20917, 20914, 20918, 20926, 20932, 20933, 20932, 20935, 20938, 20938, 20938, 20942, 20947, 20945, 20944, 20945, 20947, 20949, 20948, 20946, 20943, 20941, 20939, 20929, 20923, 20922, 20923, 20926, 20927, 20931, 20935, 20936, 20933, 20932, 20933, 20932, 20930, 20931, 20935, 20940, 20943, 20947, 20951, 20953, 20954, 20955, 20950, 20942, 20935, 20930, 20929, 20929, 20930, 20930, 20929, 20929, 20929, 20930, 20936, 20945, 20951, 20955, 20954, 20952, 20951, 20950, 20951, 20946, 20936, 20930, 20928, 20930, 20933, 20936, 20940, 20943, 20939, 20932, 20931, 20933, 20938, 20943, 20945, 20949, 20953, 20956, 20951, 20945, 20942, 20942, 20944, 20946, 20945, 20941, 20936, 20934, 20940, 20944, 20950, 20953, 20955, 20956, 20957, 20955, 20950, 20948, 20944, 20942, 20939, 20937, 20924, 20916, 20918, 20917, 20918, 20917, 20918, 20917, 20918, 20917, 20918, 20918, 20918, 20918, };