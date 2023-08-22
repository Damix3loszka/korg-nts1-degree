#include "userosc.h"
#define SNARE_SAMPLERATE 24000.0
#define SNARE_SAMPLES_COUNT 2041
#define SNARE_MIN_SAMPLE -0.304443359375
uint16_t snare_samples[SNARE_SAMPLES_COUNT] = {
23647, 23263, 24335, 23551, 24943, 22367, 24527, 21631, 24607, 21503, 24895, 26367, 24351, 27263, 27567, 25119, 26127, 21199, 10199, 37311, 1711, 28031, 15663, 19039, 21599, 7775, 20399, 22943, 32799, 10239, 28031, 2031, 30143, 19583, 5207, 23615, 37311, 19007, 11255, 4719, 18335, 29183, 6143, 9471, 18607, 23839, 6887, 14623, 17871, 30367, 10751, 25679, 13743, 6383, 28847, 17183, 20079, 22975, 5991, 29023, 20991, 7559, 41791, 17519, 33503, 31199, 14879, 32159, 14895, 3855, 18239, 30111, 11239, 4079, 5199, 16527, 8359, 1487, 15183, 3719, 5879, 2623, 10351, 10527, 18159, 7591, 10327, 23439, 17743, 11199, 17071, 26559, 30047, 33343, 21775, 16543, 11263, 35359, 27631, 37151, 26943, 16847, 38527, 28559, 33023, 28735, 22863, 31135, 34271, 33087, 19647, 15215, 27743, 30527, 32031, 31279, 27247, 32175, 36671, 26991, 27295, 30623, 32575, 26543, 30975, 18943, 23951, 24607, 12831, 16639, 15375, 24191, 9791, 8151, 5319, 8087, 9687, 0, 1455, 2479, 5327, 8487, 4759, 2463, 6575, 4423, 5767, 6319, 1503, 1839, 5319, 11415, 943, 4879, 13159, 9399, 13071, 3327, 14903, 15967, 9591, 15687, 12255, 15167, 15599, 17439, 15199, 8495, 19871, 20671, 13983, 22255, 19711, 22367, 23343, 27887, 29727, 31743, 30399, 22767, 29151, 25199, 27007, 27967, 34079, 34399, 28079, 29343, 32559, 36031, 30847, 27215, 28543, 33279, 31999, 25231, 30399, 32255, 28687, 24543, 23775, 34943, 28719, 27199, 25663, 23679, 24575, 21167, 24239, 20543, 18479, 15247, 10247, 18911, 18543, 10423, 17919, 15375, 13087, 12671, 13743, 15655, 13951, 13439, 12847, 18767, 13743, 16671, 20143, 13527, 15567, 19455, 16575, 15527, 18511, 17599, 18383, 18591, 17759, 18543, 17711, 15855, 22815, 19023, 15863, 21183, 18111, 15951, 14959, 17055, 18975, 15895, 13647, 17519, 16351, 14479, 20095, 14551, 15455, 16751, 9007, 17455, 14919, 13855, 18335, 12143, 14383, 16215, 13399, 14367, 12175, 13327, 16735, 15159, 12615, 10831, 15743, 15807, 13527, 13791, 14703, 18767, 15263, 15039, 15279, 14991, 19263, 16383, 16671, 16295, 15559, 16559, 19279, 16671, 16511, 17599, 17167, 16831, 16335, 18783, 13983, 17071, 19951, 18543, 16183, 19183, 18655, 17839, 17071, 16127, 19775, 15759, 16639, 16559, 18303, 17519, 14511, 16703, 18079, 17999, 16239, 17615, 19135, 16495, 14223, 17535, 18495, 15463, 19919, 19903, 18399, 23231, 22159, 21583, 22687, 25759, 21823, 22175, 24351, 21583, 26239, 23807, 21935, 22143, 23999, 23439, 24895, 25727, 23663, 25679, 28031, 26783, 23471, 29215, 29407, 27983, 27535, 28079, 30175, 29679, 28383, 27839, 31055, 29423, 28735, 31695, 29151, 28863, 29775, 28735, 29023, 29439, 27935, 28703, 28415, 25167, 25807, 25439, 26575, 25087, 23823, 23871, 23983, 22415, 21535, 20607, 21535, 20239, 19295, 20575, 18911, 21119, 19295, 17599, 17775, 16863, 17535, 18975, 16991, 16447, 18063, 16831, 14623, 17247, 16703, 14975, 16031, 16863, 15031, 14471, 15311, 14271, 15343, 17631, 15463, 13535, 15815, 14727, 17055, 15047, 16479, 17375, 16359, 16383, 15263, 17711, 15335, 17199, 17327, 14887, 18111, 17631, 17503, 17391, 16031, 18719, 17471, 16575, 18543, 17727, 16895, 17519, 18191, 17247, 18175, 19039, 19039, 18911, 18159, 19407, 17935, 18671, 18335, 18719, 19775, 17967, 17503, 19471, 19423, 17791, 19967, 18527, 17583, 18895, 19055, 17967, 18415, 17551, 18927, 18447, 18031, 18687, 17183, 18527, 18847, 19039, 18783, 18703, 19199, 20111, 20335, 20687, 19535, 19727, 19855, 19823, 20255, 19855, 19887, 20063, 20783, 19871, 19135, 19519, 19727, 19631, 19615, 19791, 19615, 18623, 19263, 19375, 18959, 19855, 19071, 18447, 19167, 19615, 19599, 19007, 18415, 19679, 19743, 18911, 18959, 19311, 20015, 20191, 19807, 18735, 18751, 19615, 20111, 19103, 20607, 20719, 19775, 20623, 19855, 20735, 20831, 20223, 20367, 20543, 21103, 21759, 22175, 21695, 21231, 20879, 21487, 20975, 20687, 21247, 21135, 21215, 20943, 22303, 21647, 21359, 20767, 21567, 22527, 20799, 21983, 22527, 22143, 21791, 22079, 21455, 21135, 21519, 20607, 21423, 22159, 21279, 22079, 22159, 20559, 21375, 21999, 20959, 20783, 21119, 21503, 21951, 21919, 21103, 21247, 21231, 20511, 21663, 21455, 20495, 20975, 21087, 21007, 21391, 20895, 20591, 21167, 21055, 21039, 20495, 20831, 20687, 20719, 21247, 21167, 21055, 20703, 20879, 20367, 20607, 20879, 20655, 20399, 19919, 20079, 20127, 19471, 19791, 19759, 19279, 20047, 19903, 19007, 19871, 20031, 19327, 19871, 20015, 19279, 18943, 19471, 19135, 18911, 19135, 19087, 18975, 19151, 18959, 19119, 18991, 18911, 18927, 18463, 19423, 18959, 18847, 19311, 19039, 19759, 19183, 18655, 19519, 19887, 19711, 19359, 19679, 19887, 19839, 19743, 19519, 19919, 19919, 19871, 19679, 20159, 19823, 20047, 20063, 19423, 20031, 20271, 20607, 19791, 19375, 19791, 20383, 20031, 19759, 19535, 19487, 19679, 19695, 19343, 19391, 20271, 19455, 19103, 19647, 19807, 19407, 19487, 19743, 19407, 19887, 19711, 18991, 19679, 19711, 19535, 19439, 19471, 19631, 19615, 19615, 19455, 19743, 19711, 19455, 19471, 19679, 19775, 19551, 19423, 19583, 19391, 19663, 19759, 19263, 19247, 19551, 19391, 19551, 19647, 19247, 19167, 19487, 19727, 19503, 19343, 19567, 19423, 19551, 19695, 19551, 19871, 19535, 19647, 19855, 19823, 19759, 19839, 19871, 19935, 19839, 19727, 19519, 19903, 19871, 19407, 19551, 19391, 19871, 19711, 19743, 19743, 19823, 20015, 19775, 19647, 19839, 19519, 19487, 19727, 19519, 19439, 19487, 19583, 19327, 19519, 19791, 19519, 19455, 19967, 19487, 19615, 19887, 19359, 19519, 19471, 19519, 19759, 19279, 19519, 19343, 19471, 19791, 19375, 19599, 19567, 19695, 19615, 19583, 19583, 19455, 19503, 19407, 19647, 19647, 19439, 19567, 19551, 19551, 19567, 19423, 19583, 19935, 19583, 19503, 19695, 19711, 20047, 19871, 19711, 20047, 19999, 19887, 19823, 19855, 19887, 19951, 20127, 19983, 20159, 20255, 20095, 20175, 20239, 20111, 20255, 20287, 20111, 20159, 20447, 20431, 20127, 20463, 20639, 20511, 20351, 20383, 20527, 20559, 20463, 20543, 20639, 20511, 20671, 20735, 20559, 20383, 20559, 20575, 20543, 20703, 20703, 20639, 20607, 20607, 20815, 20783, 20687, 20671, 20575, 20719, 20607, 20687, 20687, 20463, 20623, 20719, 20591, 20719, 20543, 20447, 20431, 20511, 20655, 20543, 20559, 20543, 20623, 20351, 20447, 20495, 20495, 20543, 20431, 20335, 20351, 20447, 20431, 20367, 20255, 20335, 20543, 20367, 20111, 20255, 20431, 20223, 20015, 20271, 20191, 19983, 19967, 20095, 20063, 19903, 19935, 19951, 19935, 19903, 19807, 19775, 19839, 19855, 19807, 19807, 19791, 19711, 19839, 19711, 19727, 19887, 19679, 19727, 19823, 19663, 19823, 19807, 19839, 19919, 19807, 19839, 19759, 19887, 19983, 19903, 19935, 20047, 19887, 19871, 20015, 19823, 19919, 20031, 19871, 19919, 19903, 19903, 19919, 19791, 19951, 20031, 20015, 19903, 19919, 20047, 19807, 19951, 19935, 19823, 19935, 19903, 19919, 19807, 19919, 19951, 19839, 19887, 19807, 19903, 19951, 19759, 19855, 19823, 19791, 19887, 19887, 19791, 19743, 19823, 19743, 19775, 19679, 19791, 19791, 19647, 19743, 19743, 19647, 19711, 19711, 19727, 19599, 19631, 19695, 19567, 19695, 19503, 19631, 19647, 19535, 19711, 19615, 19631, 19599, 19599, 19695, 19583, 19663, 19727, 19615, 19631, 19727, 19631, 19711, 19599, 19711, 19695, 19583, 19791, 19583, 19823, 19647, 19759, 19759, 19695, 19775, 19695, 19775, 19743, 19855, 19727, 19887, 19759, 19887, 19823, 19839, 19951, 19839, 19887, 19935, 19903, 19887, 20015, 19823, 19967, 19887, 19919, 19855, 19919, 19855, 19807, 19887, 19887, 19839, 19759, 19935, 19711, 19871, 19743, 19775, 19807, 19727, 19839, 19711, 19823, 19727, 19775, 19743, 19759, 19759, 19727, 19727, 19711, 19775, 19727, 19743, 19759, 19743, 19775, 19743, 19743, 19759, 19711, 19791, 19743, 19759, 19775, 19759, 19775, 19743, 19839, 19791, 19807, 19839, 19775, 19807, 19855, 19855, 19855, 19839, 19855, 19887, 19903, 19871, 19903, 19887, 19887, 19935, 19919, 19935, 19919, 19935, 19967, 19967, 19967, 19967, 19983, 19967, 19967, 19999, 19999, 19999, 20031, 19999, 20015, 20015, 20015, 20047, 20015, 20015, 20031, 20047, 20047, 20047, 20047, 20047, 20063, 20063, 20063, 20047, 20047, 20063, 20063, 20095, 20079, 20079, 20095, 20079, 20079, 20079, 20079, 20079, 20079, 20063, 20095, 20095, 20079, 20095, 20079, 20079, 20063, 20095, 20079, 20079, 20063, 20079, 20063, 20031, 20063, 20047, 20063, 20063, 20031, 20063, 20047, 20063, 20047, 20031, 20031, 20031, 20031, 20031, 20031, 20015, 20015, 20031, 20031, 20031, 20015, 20031, 20015, 20015, 20031, 20015, 19999, 20015, 20015, 19999, 20015, 19999, 19983, 20015, 19999, 19999, 19999, 19999, 19967, 19967, 19983, 19967, 19967, 19967, 19967, 19951, 19967, 19951, 19951, 19951, 19951, 19967, 19967, 19951, 19967, 19967, 19983, 19983, 19967, 19967, 19983, 19967, 19983, 19983, 19999, 19999, 19999, 20015, 20015, 19999, 19999, 20015, 20015, 20015, 20015, 20031, 20031, 20031, 20031, 20031, 20031, 20031, 20031, 20031, 20031, 20031, 20031, 20031, 20031, 20015, 20015, 20015, 20031, 20015, 20015, 20031, 20015, 20015, 20015, 20015, 19999, 19999, 19999, 19999, 19999, 19983, 19983, 19983, 19983, 19983, 19967, 19967, 19967, 19967, 19967, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19935, 19935, 19951, 19951, 19935, 19951, 19951, 19935, 19951, 19935, 19951, 19951, 19951, 19951, 19951, 19951, 19935, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19935, 19951, 19935, 19935, 19951, 19935, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, 19951, };