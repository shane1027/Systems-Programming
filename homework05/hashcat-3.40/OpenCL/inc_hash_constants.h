/**
 * Author......: See docs/credits.txt
 * License.....: MIT
 */

typedef enum siphash_constants
{
  SIPHASHM_0=0x736f6d6570736575,
  SIPHASHM_1=0x646f72616e646f6d,
  SIPHASHM_2=0x6c7967656e657261,
  SIPHASHM_3=0x7465646279746573

} siphash_constants_t;

typedef enum bcrypt_constants
{
  BCRYPTM_0=0x4F727068,
  BCRYPTM_1=0x65616E42,
  BCRYPTM_2=0x65686F6C,
  BCRYPTM_3=0x64657253,
  BCRYPTM_4=0x63727944,
  BCRYPTM_5=0x6F756274u

} bcrypt_constants_t;

typedef enum md4_constants
{
  MD4M_A=0x67452301,
  MD4M_B=0xefcdab89,
  MD4M_C=0x98badcfe,
  MD4M_D=0x10325476,

  MD4S00=3,
  MD4S01=7,
  MD4S02=11,
  MD4S03=19,
  MD4S10=3,
  MD4S11=5,
  MD4S12=9,
  MD4S13=13,
  MD4S20=3,
  MD4S21=9,
  MD4S22=11,
  MD4S23=15,

  MD4C00=0x00000000,
  MD4C01=0x5a827999,
  MD4C02=0x6ed9eba1u

} md4_constants_t;

typedef enum md5_constants
{
  MD5M_A=0x67452301,
  MD5M_B=0xefcdab89,
  MD5M_C=0x98badcfe,
  MD5M_D=0x10325476,

  MD5S00=7,
  MD5S01=12,
  MD5S02=17,
  MD5S03=22,
  MD5S10=5,
  MD5S11=9,
  MD5S12=14,
  MD5S13=20,
  MD5S20=4,
  MD5S21=11,
  MD5S22=16,
  MD5S23=23,
  MD5S30=6,
  MD5S31=10,
  MD5S32=15,
  MD5S33=21,

  MD5C00=0xd76aa478,
  MD5C01=0xe8c7b756,
  MD5C02=0x242070db,
  MD5C03=0xc1bdceee,
  MD5C04=0xf57c0faf,
  MD5C05=0x4787c62a,
  MD5C06=0xa8304613,
  MD5C07=0xfd469501,
  MD5C08=0x698098d8,
  MD5C09=0x8b44f7af,
  MD5C0a=0xffff5bb1,
  MD5C0b=0x895cd7be,
  MD5C0c=0x6b901122,
  MD5C0d=0xfd987193,
  MD5C0e=0xa679438e,
  MD5C0f=0x49b40821,
  MD5C10=0xf61e2562,
  MD5C11=0xc040b340,
  MD5C12=0x265e5a51,
  MD5C13=0xe9b6c7aa,
  MD5C14=0xd62f105d,
  MD5C15=0x02441453,
  MD5C16=0xd8a1e681,
  MD5C17=0xe7d3fbc8,
  MD5C18=0x21e1cde6,
  MD5C19=0xc33707d6,
  MD5C1a=0xf4d50d87,
  MD5C1b=0x455a14ed,
  MD5C1c=0xa9e3e905,
  MD5C1d=0xfcefa3f8,
  MD5C1e=0x676f02d9,
  MD5C1f=0x8d2a4c8a,
  MD5C20=0xfffa3942,
  MD5C21=0x8771f681,
  MD5C22=0x6d9d6122,
  MD5C23=0xfde5380c,
  MD5C24=0xa4beea44,
  MD5C25=0x4bdecfa9,
  MD5C26=0xf6bb4b60,
  MD5C27=0xbebfbc70,
  MD5C28=0x289b7ec6,
  MD5C29=0xeaa127fa,
  MD5C2a=0xd4ef3085,
  MD5C2b=0x04881d05,
  MD5C2c=0xd9d4d039,
  MD5C2d=0xe6db99e5,
  MD5C2e=0x1fa27cf8,
  MD5C2f=0xc4ac5665,
  MD5C30=0xf4292244,
  MD5C31=0x432aff97,
  MD5C32=0xab9423a7,
  MD5C33=0xfc93a039,
  MD5C34=0x655b59c3,
  MD5C35=0x8f0ccc92,
  MD5C36=0xffeff47d,
  MD5C37=0x85845dd1,
  MD5C38=0x6fa87e4f,
  MD5C39=0xfe2ce6e0,
  MD5C3a=0xa3014314,
  MD5C3b=0x4e0811a1,
  MD5C3c=0xf7537e82,
  MD5C3d=0xbd3af235,
  MD5C3e=0x2ad7d2bb,
  MD5C3f=0xeb86d391u

} md5_constants_t;

typedef enum sha1_constants
{
  SHA1M_A=0x67452301,
  SHA1M_B=0xefcdab89,
  SHA1M_C=0x98badcfe,
  SHA1M_D=0x10325476,
  SHA1M_E=0xc3d2e1f0,

  SHA1C00=0x5a827999,
  SHA1C01=0x6ed9eba1,
  SHA1C02=0x8f1bbcdc,
  SHA1C03=0xca62c1d6u

} sha1_constants_t;

typedef enum sha2_32_constants
{
  // SHA-224 Initial Hash Values
  SHA224M_A=0xc1059ed8,
  SHA224M_B=0x367cd507,
  SHA224M_C=0x3070dd17,
  SHA224M_D=0xf70e5939,
  SHA224M_E=0xffc00b31,
  SHA224M_F=0x68581511,
  SHA224M_G=0x64f98fa7,
  SHA224M_H=0xbefa4fa4,

  // SHA-256 Initial Hash Values
  SHA256M_A=0x6a09e667,
  SHA256M_B=0xbb67ae85,
  SHA256M_C=0x3c6ef372,
  SHA256M_D=0xa54ff53a,
  SHA256M_E=0x510e527f,
  SHA256M_F=0x9b05688c,
  SHA256M_G=0x1f83d9ab,
  SHA256M_H=0x5be0cd19,

  // SHA-224/256 Constants
  SHA256C00=0x428a2f98,
  SHA256C01=0x71374491,
  SHA256C02=0xb5c0fbcf,
  SHA256C03=0xe9b5dba5,
  SHA256C04=0x3956c25b,
  SHA256C05=0x59f111f1,
  SHA256C06=0x923f82a4,
  SHA256C07=0xab1c5ed5,
  SHA256C08=0xd807aa98,
  SHA256C09=0x12835b01,
  SHA256C0a=0x243185be,
  SHA256C0b=0x550c7dc3,
  SHA256C0c=0x72be5d74,
  SHA256C0d=0x80deb1fe,
  SHA256C0e=0x9bdc06a7,
  SHA256C0f=0xc19bf174,
  SHA256C10=0xe49b69c1,
  SHA256C11=0xefbe4786,
  SHA256C12=0x0fc19dc6,
  SHA256C13=0x240ca1cc,
  SHA256C14=0x2de92c6f,
  SHA256C15=0x4a7484aa,
  SHA256C16=0x5cb0a9dc,
  SHA256C17=0x76f988da,
  SHA256C18=0x983e5152,
  SHA256C19=0xa831c66d,
  SHA256C1a=0xb00327c8,
  SHA256C1b=0xbf597fc7,
  SHA256C1c=0xc6e00bf3,
  SHA256C1d=0xd5a79147,
  SHA256C1e=0x06ca6351,
  SHA256C1f=0x14292967,
  SHA256C20=0x27b70a85,
  SHA256C21=0x2e1b2138,
  SHA256C22=0x4d2c6dfc,
  SHA256C23=0x53380d13,
  SHA256C24=0x650a7354,
  SHA256C25=0x766a0abb,
  SHA256C26=0x81c2c92e,
  SHA256C27=0x92722c85,
  SHA256C28=0xa2bfe8a1,
  SHA256C29=0xa81a664b,
  SHA256C2a=0xc24b8b70,
  SHA256C2b=0xc76c51a3,
  SHA256C2c=0xd192e819,
  SHA256C2d=0xd6990624,
  SHA256C2e=0xf40e3585,
  SHA256C2f=0x106aa070,
  SHA256C30=0x19a4c116,
  SHA256C31=0x1e376c08,
  SHA256C32=0x2748774c,
  SHA256C33=0x34b0bcb5,
  SHA256C34=0x391c0cb3,
  SHA256C35=0x4ed8aa4a,
  SHA256C36=0x5b9cca4f,
  SHA256C37=0x682e6ff3,
  SHA256C38=0x748f82ee,
  SHA256C39=0x78a5636f,
  SHA256C3a=0x84c87814,
  SHA256C3b=0x8cc70208,
  SHA256C3c=0x90befffa,
  SHA256C3d=0xa4506ceb,
  SHA256C3e=0xbef9a3f7,
  SHA256C3f=0xc67178f2

} sha2_32_constants_t;

typedef enum sha2_64_constants
{
  // SHA-384 Initial Hash Values
  SHA384M_A=0xcbbb9d5dc1059ed8,
  SHA384M_B=0x629a292a367cd507,
  SHA384M_C=0x9159015a3070dd17,
  SHA384M_D=0x152fecd8f70e5939,
  SHA384M_E=0x67332667ffc00b31,
  SHA384M_F=0x8eb44a8768581511,
  SHA384M_G=0xdb0c2e0d64f98fa7,
  SHA384M_H=0x47b5481dbefa4fa4,

  // SHA-512 Initial Hash Values
  SHA512M_A=0x6a09e667f3bcc908,
  SHA512M_B=0xbb67ae8584caa73b,
  SHA512M_C=0x3c6ef372fe94f82b,
  SHA512M_D=0xa54ff53a5f1d36f1,
  SHA512M_E=0x510e527fade682d1,
  SHA512M_F=0x9b05688c2b3e6c1f,
  SHA512M_G=0x1f83d9abfb41bd6b,
  SHA512M_H=0x5be0cd19137e2179,

  // SHA-384/512 Constants
  SHA512C00=0x428a2f98d728ae22,
  SHA512C01=0x7137449123ef65cd,
  SHA512C02=0xb5c0fbcfec4d3b2f,
  SHA512C03=0xe9b5dba58189dbbc,
  SHA512C04=0x3956c25bf348b538,
  SHA512C05=0x59f111f1b605d019,
  SHA512C06=0x923f82a4af194f9b,
  SHA512C07=0xab1c5ed5da6d8118,
  SHA512C08=0xd807aa98a3030242,
  SHA512C09=0x12835b0145706fbe,
  SHA512C0a=0x243185be4ee4b28c,
  SHA512C0b=0x550c7dc3d5ffb4e2,
  SHA512C0c=0x72be5d74f27b896f,
  SHA512C0d=0x80deb1fe3b1696b1,
  SHA512C0e=0x9bdc06a725c71235,
  SHA512C0f=0xc19bf174cf692694,
  SHA512C10=0xe49b69c19ef14ad2,
  SHA512C11=0xefbe4786384f25e3,
  SHA512C12=0x0fc19dc68b8cd5b5,
  SHA512C13=0x240ca1cc77ac9c65,
  SHA512C14=0x2de92c6f592b0275,
  SHA512C15=0x4a7484aa6ea6e483,
  SHA512C16=0x5cb0a9dcbd41fbd4,
  SHA512C17=0x76f988da831153b5,
  SHA512C18=0x983e5152ee66dfab,
  SHA512C19=0xa831c66d2db43210,
  SHA512C1a=0xb00327c898fb213f,
  SHA512C1b=0xbf597fc7beef0ee4,
  SHA512C1c=0xc6e00bf33da88fc2,
  SHA512C1d=0xd5a79147930aa725,
  SHA512C1e=0x06ca6351e003826f,
  SHA512C1f=0x142929670a0e6e70,
  SHA512C20=0x27b70a8546d22ffc,
  SHA512C21=0x2e1b21385c26c926,
  SHA512C22=0x4d2c6dfc5ac42aed,
  SHA512C23=0x53380d139d95b3df,
  SHA512C24=0x650a73548baf63de,
  SHA512C25=0x766a0abb3c77b2a8,
  SHA512C26=0x81c2c92e47edaee6,
  SHA512C27=0x92722c851482353b,
  SHA512C28=0xa2bfe8a14cf10364,
  SHA512C29=0xa81a664bbc423001,
  SHA512C2a=0xc24b8b70d0f89791,
  SHA512C2b=0xc76c51a30654be30,
  SHA512C2c=0xd192e819d6ef5218,
  SHA512C2d=0xd69906245565a910,
  SHA512C2e=0xf40e35855771202a,
  SHA512C2f=0x106aa07032bbd1b8,
  SHA512C30=0x19a4c116b8d2d0c8,
  SHA512C31=0x1e376c085141ab53,
  SHA512C32=0x2748774cdf8eeb99,
  SHA512C33=0x34b0bcb5e19b48a8,
  SHA512C34=0x391c0cb3c5c95a63,
  SHA512C35=0x4ed8aa4ae3418acb,
  SHA512C36=0x5b9cca4f7763e373,
  SHA512C37=0x682e6ff3d6b2b8a3,
  SHA512C38=0x748f82ee5defb2fc,
  SHA512C39=0x78a5636f43172f60,
  SHA512C3a=0x84c87814a1f0ab72,
  SHA512C3b=0x8cc702081a6439ec,
  SHA512C3c=0x90befffa23631e28,
  SHA512C3d=0xa4506cebde82bde9,
  SHA512C3e=0xbef9a3f7b2c67915,
  SHA512C3f=0xc67178f2e372532b,
  SHA512C40=0xca273eceea26619c,
  SHA512C41=0xd186b8c721c0c207,
  SHA512C42=0xeada7dd6cde0eb1e,
  SHA512C43=0xf57d4f7fee6ed178,
  SHA512C44=0x06f067aa72176fba,
  SHA512C45=0x0a637dc5a2c898a6,
  SHA512C46=0x113f9804bef90dae,
  SHA512C47=0x1b710b35131c471b,
  SHA512C48=0x28db77f523047d84,
  SHA512C49=0x32caab7b40c72493,
  SHA512C4a=0x3c9ebe0a15c9bebc,
  SHA512C4b=0x431d67c49c100d4c,
  SHA512C4c=0x4cc5d4becb3e42b6,
  SHA512C4d=0x597f299cfc657e2a,
  SHA512C4e=0x5fcb6fab3ad6faec,
  SHA512C4f=0x6c44198c4a475817

} sha2_64_constants_t;

typedef enum ripemd160_constants
{
  RIPEMD160M_A=0x67452301,
  RIPEMD160M_B=0xefcdab89,
  RIPEMD160M_C=0x98badcfe,
  RIPEMD160M_D=0x10325476,
  RIPEMD160M_E=0xc3d2e1f0,

  RIPEMD160C00=0x00000000,
  RIPEMD160C10=0x5a827999,
  RIPEMD160C20=0x6ed9eba1,
  RIPEMD160C30=0x8f1bbcdc,
  RIPEMD160C40=0xa953fd4e,
  RIPEMD160C50=0x50a28be6,
  RIPEMD160C60=0x5c4dd124,
  RIPEMD160C70=0x6d703ef3,
  RIPEMD160C80=0x7a6d76e9,
  RIPEMD160C90=0x00000000,

  RIPEMD160S00=11,
  RIPEMD160S01=14,
  RIPEMD160S02=15,
  RIPEMD160S03=12,
  RIPEMD160S04=5,
  RIPEMD160S05=8,
  RIPEMD160S06=7,
  RIPEMD160S07=9,
  RIPEMD160S08=11,
  RIPEMD160S09=13,
  RIPEMD160S0A=14,
  RIPEMD160S0B=15,
  RIPEMD160S0C=6,
  RIPEMD160S0D=7,
  RIPEMD160S0E=9,
  RIPEMD160S0F=8,

  RIPEMD160S10=7,
  RIPEMD160S11=6,
  RIPEMD160S12=8,
  RIPEMD160S13=13,
  RIPEMD160S14=11,
  RIPEMD160S15=9,
  RIPEMD160S16=7,
  RIPEMD160S17=15,
  RIPEMD160S18=7,
  RIPEMD160S19=12,
  RIPEMD160S1A=15,
  RIPEMD160S1B=9,
  RIPEMD160S1C=11,
  RIPEMD160S1D=7,
  RIPEMD160S1E=13,
  RIPEMD160S1F=12,

  RIPEMD160S20=11,
  RIPEMD160S21=13,
  RIPEMD160S22=6,
  RIPEMD160S23=7,
  RIPEMD160S24=14,
  RIPEMD160S25=9,
  RIPEMD160S26=13,
  RIPEMD160S27=15,
  RIPEMD160S28=14,
  RIPEMD160S29=8,
  RIPEMD160S2A=13,
  RIPEMD160S2B=6,
  RIPEMD160S2C=5,
  RIPEMD160S2D=12,
  RIPEMD160S2E=7,
  RIPEMD160S2F=5,

  RIPEMD160S30=11,
  RIPEMD160S31=12,
  RIPEMD160S32=14,
  RIPEMD160S33=15,
  RIPEMD160S34=14,
  RIPEMD160S35=15,
  RIPEMD160S36=9,
  RIPEMD160S37=8,
  RIPEMD160S38=9,
  RIPEMD160S39=14,
  RIPEMD160S3A=5,
  RIPEMD160S3B=6,
  RIPEMD160S3C=8,
  RIPEMD160S3D=6,
  RIPEMD160S3E=5,
  RIPEMD160S3F=12,

  RIPEMD160S40=9,
  RIPEMD160S41=15,
  RIPEMD160S42=5,
  RIPEMD160S43=11,
  RIPEMD160S44=6,
  RIPEMD160S45=8,
  RIPEMD160S46=13,
  RIPEMD160S47=12,
  RIPEMD160S48=5,
  RIPEMD160S49=12,
  RIPEMD160S4A=13,
  RIPEMD160S4B=14,
  RIPEMD160S4C=11,
  RIPEMD160S4D=8,
  RIPEMD160S4E=5,
  RIPEMD160S4F=6,

  RIPEMD160S50=8,
  RIPEMD160S51=9,
  RIPEMD160S52=9,
  RIPEMD160S53=11,
  RIPEMD160S54=13,
  RIPEMD160S55=15,
  RIPEMD160S56=15,
  RIPEMD160S57=5,
  RIPEMD160S58=7,
  RIPEMD160S59=7,
  RIPEMD160S5A=8,
  RIPEMD160S5B=11,
  RIPEMD160S5C=14,
  RIPEMD160S5D=14,
  RIPEMD160S5E=12,
  RIPEMD160S5F=6,

  RIPEMD160S60=9,
  RIPEMD160S61=13,
  RIPEMD160S62=15,
  RIPEMD160S63=7,
  RIPEMD160S64=12,
  RIPEMD160S65=8,
  RIPEMD160S66=9,
  RIPEMD160S67=11,
  RIPEMD160S68=7,
  RIPEMD160S69=7,
  RIPEMD160S6A=12,
  RIPEMD160S6B=7,
  RIPEMD160S6C=6,
  RIPEMD160S6D=15,
  RIPEMD160S6E=13,
  RIPEMD160S6F=11,

  RIPEMD160S70=9,
  RIPEMD160S71=7,
  RIPEMD160S72=15,
  RIPEMD160S73=11,
  RIPEMD160S74=8,
  RIPEMD160S75=6,
  RIPEMD160S76=6,
  RIPEMD160S77=14,
  RIPEMD160S78=12,
  RIPEMD160S79=13,
  RIPEMD160S7A=5,
  RIPEMD160S7B=14,
  RIPEMD160S7C=13,
  RIPEMD160S7D=13,
  RIPEMD160S7E=7,
  RIPEMD160S7F=5,

  RIPEMD160S80=15,
  RIPEMD160S81=5,
  RIPEMD160S82=8,
  RIPEMD160S83=11,
  RIPEMD160S84=14,
  RIPEMD160S85=14,
  RIPEMD160S86=6,
  RIPEMD160S87=14,
  RIPEMD160S88=6,
  RIPEMD160S89=9,
  RIPEMD160S8A=12,
  RIPEMD160S8B=9,
  RIPEMD160S8C=12,
  RIPEMD160S8D=5,
  RIPEMD160S8E=15,
  RIPEMD160S8F=8,

  RIPEMD160S90=8,
  RIPEMD160S91=5,
  RIPEMD160S92=12,
  RIPEMD160S93=9,
  RIPEMD160S94=12,
  RIPEMD160S95=5,
  RIPEMD160S96=14,
  RIPEMD160S97=6,
  RIPEMD160S98=8,
  RIPEMD160S99=13,
  RIPEMD160S9A=6,
  RIPEMD160S9B=5,
  RIPEMD160S9C=15,
  RIPEMD160S9D=13,
  RIPEMD160S9E=11,
  RIPEMD160S9F=11u

} ripemd160_constants_t;

typedef enum keccak_constants
{
  KECCAK_RNDC_00=0x0000000000000001,
  KECCAK_RNDC_01=0x0000000000008082,
  KECCAK_RNDC_02=0x000000000000808a,
  KECCAK_RNDC_03=0x0000000080008000,
  KECCAK_RNDC_04=0x000000000000808b,
  KECCAK_RNDC_05=0x0000000080000001,
  KECCAK_RNDC_06=0x0000000080008081,
  KECCAK_RNDC_07=0x0000000000008009,
  KECCAK_RNDC_08=0x000000000000008a,
  KECCAK_RNDC_09=0x0000000000000088,
  KECCAK_RNDC_10=0x0000000080008009,
  KECCAK_RNDC_11=0x000000008000000a,
  KECCAK_RNDC_12=0x000000008000808b,
  KECCAK_RNDC_13=0x000000000000008b,
  KECCAK_RNDC_14=0x0000000000008089,
  KECCAK_RNDC_15=0x0000000000008003,
  KECCAK_RNDC_16=0x0000000000008002,
  KECCAK_RNDC_17=0x0000000000000080,
  KECCAK_RNDC_18=0x000000000000800a,
  KECCAK_RNDC_19=0x000000008000000a,
  KECCAK_RNDC_20=0x0000000080008081,
  KECCAK_RNDC_21=0x0000000000008080,
  KECCAK_RNDC_22=0x0000000080000001,
  KECCAK_RNDC_23=0x0000000080008008,

  KECCAK_PILN_00=10,
  KECCAK_PILN_01=7,
  KECCAK_PILN_02=11,
  KECCAK_PILN_03=17,
  KECCAK_PILN_04=18,
  KECCAK_PILN_05=3,
  KECCAK_PILN_06=5,
  KECCAK_PILN_07=16,
  KECCAK_PILN_08=8,
  KECCAK_PILN_09=21,
  KECCAK_PILN_10=24,
  KECCAK_PILN_11=4,
  KECCAK_PILN_12=15,
  KECCAK_PILN_13=23,
  KECCAK_PILN_14=19,
  KECCAK_PILN_15=13,
  KECCAK_PILN_16=12,
  KECCAK_PILN_17=2,
  KECCAK_PILN_18=20,
  KECCAK_PILN_19=14,
  KECCAK_PILN_20=22,
  KECCAK_PILN_21=9,
  KECCAK_PILN_22=6,
  KECCAK_PILN_23=1,

  KECCAK_ROTC_00=1,
  KECCAK_ROTC_01=3,
  KECCAK_ROTC_02=6,
  KECCAK_ROTC_03=10,
  KECCAK_ROTC_04=15,
  KECCAK_ROTC_05=21,
  KECCAK_ROTC_06=28,
  KECCAK_ROTC_07=36,
  KECCAK_ROTC_08=45,
  KECCAK_ROTC_09=55,
  KECCAK_ROTC_10=2,
  KECCAK_ROTC_11=14,
  KECCAK_ROTC_12=27,
  KECCAK_ROTC_13=41,
  KECCAK_ROTC_14=56,
  KECCAK_ROTC_15=8,
  KECCAK_ROTC_16=25,
  KECCAK_ROTC_17=43,
  KECCAK_ROTC_18=62,
  KECCAK_ROTC_19=18,
  KECCAK_ROTC_20=39,
  KECCAK_ROTC_21=61,
  KECCAK_ROTC_22=20,
  KECCAK_ROTC_23=44,

} keccak_constants_t;

typedef enum mysql323_constants
{
  MYSQL323_A=0x50305735,
  MYSQL323_B=0x12345671u

} mysql323_constants_t;

typedef enum fortigate_constants
{
  FORTIGATE_A=0x2eba88a3,
  FORTIGATE_B=0x4ab04c42,
  FORTIGATE_C=0xc1307953,
  FORTIGATE_D=0x3fcc0731,
  FORTIGATE_E=0x299032a1,
  FORTIGATE_F=0x705b81a9

} fortigate_constants_t;