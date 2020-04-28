#include "gtest.h"
#include "MaafLajbrry.h"

class MathTest : public ::testing::Test
{
protected:
	virtual void SetUp() {
		srand(time(NULL));
	}

	MaafLajbrry lib;
};


TEST_F(MathTest, Soucet)
{
	double aScitanec = rand();
	double bScitanec = rand();
	double soucet1 = lib.add(aScitanec, bScitanec);
	EXPECT_EQ(soucet1, aScitanec + bScitanec);

	double soucet2 = lib.add(bScitanec, aScitanec);
	EXPECT_EQ(soucet1, soucet2);

	soucet1 = lib.add(aScitanec, -bScitanec);
	double bNegScitanec = bScitanec * (-1);
	soucet2 = lib.add(aScitanec, bNegScitanec);
	EXPECT_EQ(soucet1, soucet2);

	double aNegScitanec = aScitanec * (-1);
	soucet1 = lib.add(aScitanec, bScitanec);
	soucet2 = lib.add(aNegScitanec, bNegScitanec);
	EXPECT_EQ(soucet1 * (-1), soucet2);

	soucet1 = lib.add(aScitanec, 0);
	EXPECT_EQ(soucet1, aScitanec);

}

TEST_F(MathTest, Rozdil)
{
	double mensenec = rand();
	double mensitel = rand();
	double rozdil = lib.sub(mensenec, mensitel);
	EXPECT_EQ(rozdil, mensenec - mensitel);

	double mensitelNeg = mensitel * (-1);
	rozdil = lib.sub(mensenec, mensitelNeg);
	EXPECT_EQ(rozdil, mensenec + mensitel);

	double mensenecNeg = mensenec * (-1);
	rozdil = lib.sub(mensenecNeg, mensitelNeg);
	EXPECT_EQ(rozdil, mensitel - mensenec);

	rozdil = lib.sub(mensenec, 0);
	EXPECT_EQ(rozdil, mensenec);
}

TEST_F(MathTest, Soucin)
{

	double aCinitel = rand();
	double bCinitel = rand();
	double soucin = lib.mul(aCinitel, bCinitel);
	EXPECT_EQ(soucin, aCinitel * bCinitel);

	soucin = lib.mul(aCinitel, 0);
	EXPECT_EQ(soucin, 0);

	double recipCinitel = 1 / aCinitel;
	soucin = lib.mul(recipCinitel, aCinitel);
	EXPECT_TRUE(fabs(soucin - 1) < std::numeric_limits<double>::epsilon() * aCinitel);

	soucin = lib.mul(aCinitel, 1);
	EXPECT_EQ(soucin, aCinitel);
}

TEST_F(MathTest, Podil)
{
	double delenec = rand();
	double delitel = rand();
	double podil = lib.divid(delenec, delitel);
	EXPECT_EQ(podil, delenec / delitel);

	EXPECT_ANY_THROW(lib.divid(delenec, 0));

	podil = lib.divid(delenec, 1);
	EXPECT_EQ(podil, delenec);
}

TEST_F(MathTest, Faktorial)
{

	int n = 13;
	long long int nFaktorial = lib.factorial(n);
	EXPECT_EQ(nFaktorial, 6227020800);

	n = 0;
	nFaktorial = lib.factorial(n);
	EXPECT_EQ(nFaktorial, 1);

	n = rand() % 20 + 1;
	nFaktorial = lib.factorial(n);
	EXPECT_EQ(nFaktorial, lib.factorial(n - 1) * n);


	EXPECT_ANY_THROW(lib.factorial(-1));

}

TEST_F(MathTest, Mocnina)
{


	double aZaklad = rand() % 1000 + 1;
	double bZaklad = rand() % 1000;
	double aExponent = rand() % 30;
	double bExponent = rand() % 30;
	double aMocnina;
	double bMocnina;

	aMocnina = lib.pow(aZaklad * bZaklad, aExponent);
	bMocnina = lib.pow(aZaklad, aExponent) * lib.pow(bZaklad, aExponent);
	EXPECT_TRUE(fabs(aMocnina - bMocnina) <= std::numeric_limits<double>::epsilon() * (aMocnina + bMocnina) * 10);

	aMocnina = lib.pow(aZaklad, aExponent) * lib.pow(aZaklad, bExponent);
	bMocnina = lib.pow(aZaklad, (aExponent + bExponent));
	EXPECT_TRUE(fabs(aMocnina - bMocnina) <= std::numeric_limits<double>::epsilon() * (aMocnina + bMocnina) * 10);

	aMocnina = lib.pow(aZaklad, aExponent) / lib.pow(aZaklad, bExponent);
	bMocnina = lib.pow(aZaklad, (aExponent - bExponent));
	EXPECT_TRUE(fabs(aMocnina - bMocnina) <= std::numeric_limits<double>::epsilon() * (aMocnina + bMocnina) * 10);

	bExponent = (int)bExponent % 5;
	aExponent = (int)aExponent % 10;
	aMocnina = lib.pow(lib.pow(aZaklad, aExponent), bExponent);
	bMocnina = lib.pow(aZaklad, aExponent * bExponent);

	EXPECT_TRUE(fabs(aMocnina - bMocnina) <= std::numeric_limits<double>::epsilon() * (aMocnina + bMocnina) * 10);

	EXPECT_EQ(lib.pow(aZaklad, 1), aZaklad);

	EXPECT_EQ(lib.pow(0, 0), 1);

	EXPECT_EQ(lib.pow(aZaklad, 0), 1);

	EXPECT_EQ(lib.pow(0 - aZaklad, 0), 1);

}

TEST_F(MathTest, Odmocnina)
{
	double aOdmocnenec = rand();
	double bOdmocnenec = rand();
	double aOdmocnitel = rand() % 10 + 1;
	double bOdmocnitel = rand() % 10 + 1;
	double aOdmocnina;
	double bOdmocnina;

	EXPECT_EQ(lib.rad(0, aOdmocnitel), 0);

	EXPECT_EQ(lib.rad(1, aOdmocnitel), 1);

	EXPECT_TRUE(fabs(lib.rad(aOdmocnenec, 1) - aOdmocnenec) < 2 * MaafLajbrryEpsilon);

	EXPECT_TRUE(fabs(aOdmocnenec - lib.rad(aOdmocnenec, 1)) < 2 * MaafLajbrryEpsilon);

	aOdmocnina = lib.rad(aOdmocnenec * bOdmocnenec, aOdmocnitel);
	bOdmocnina = lib.rad(aOdmocnenec, aOdmocnitel) * lib.rad(bOdmocnenec, aOdmocnitel);
	EXPECT_TRUE(fabs(aOdmocnina - bOdmocnina) < MaafLajbrryEpsilon * (aOdmocnenec + bOdmocnenec) * 10);


	aOdmocnina = lib.rad(aOdmocnenec, aOdmocnitel * bOdmocnitel);
	bOdmocnina = lib.rad(lib.rad(aOdmocnenec, aOdmocnitel), bOdmocnitel);

	EXPECT_TRUE(fabs(aOdmocnina - bOdmocnina) < MaafLajbrryEpsilon * (aOdmocnenec + bOdmocnenec) * 10);
	aOdmocnenec++;

	EXPECT_ANY_THROW(lib.rad(0 - aOdmocnenec, 2 * aOdmocnitel));

}
TEST_F(MathTest, KombinacniCislo)
{

	std::map<int, int> mapHranice = {
		{1, INT_MAX},
		{2, INT_MAX},
		{3, 2097153},
		{4, 55110},
		{5, 6210},
		{6, 1450},
		{7, 515},
		{8, 238},
		{9, 132},
		{10, 83},
		{11, 58},
		{12, 42},
		{13, 35},
		{14, 29}
	};

	for (int i = 1; i < 14; i++) {

		int cisloN = rand() % (mapHranice[i] - i) + i;
		int cisloK = i;
		long long aKombinace;
		long long bKombinace;

		EXPECT_ANY_THROW(lib.komb(-cisloN, cisloK));
		EXPECT_ANY_THROW(lib.komb(cisloN, -cisloK));
		EXPECT_ANY_THROW(lib.komb(cisloN, cisloN + 1));
		EXPECT_ANY_THROW(lib.komb(mapHranice[cisloK] + 1, cisloK));

		aKombinace = lib.komb(cisloN, cisloK);
		bKombinace = lib.komb(cisloN, cisloN - cisloK);
		EXPECT_EQ(aKombinace, bKombinace);

		aKombinace = lib.komb(cisloN + 1, cisloK);
		bKombinace = lib.komb(cisloN, cisloK) + lib.komb(cisloN, cisloK - 1);
		EXPECT_EQ(aKombinace, bKombinace);

		EXPECT_EQ(lib.komb(cisloN, 1), cisloN);
		EXPECT_EQ(lib.komb(cisloN, 0), 1);
		EXPECT_EQ(lib.komb(cisloN, cisloN), 1);

		cisloN = rand() % (mapHranice[cisloK + 1] - cisloK - 1) + cisloK + 1;
		aKombinace = lib.komb(cisloN, cisloK + 1);
		bKombinace = lib.komb(cisloN, cisloK) * (cisloN - cisloK) / (cisloK + 1);
		EXPECT_EQ(aKombinace, bKombinace);

	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}