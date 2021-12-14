#include <fl/util.h>

sead::Vector3f fl::QuatToEuler(sead::Quatf *quat) {

    f32 x = quat->z;
    f32 y = quat->y;
    f32 z = quat->x;
    f32 w = quat->w;

    f32 t0 = 2.0 * (w * x + y * z);
    f32 t1 = 1.0 - 2.0 * (x * x + y * y);
    f32 roll = atan2f(t0, t1);

    f32 t2 = 2.0 * (w * y - z * x);
    t2 = t2 > 1.0 ? 1.0 : t2;
    t2 = t2 < -1.0 ? -1.0 : t2;
    f32 pitch = asinf(t2);

    f32 t3 = 2.0 * (w * z + x * y);
    f32 t4 = 1.0 - 2.0 * (y * y + z * z);
    f32 yaw = atan2f(t3, t4);

    return sead::Vector3f(yaw, pitch, roll);
}

void* fl::memset (void *dest, int val, size_t len)
{
  unsigned char *ptr = (unsigned char*) dest;
  while (len-- > 0)
    *ptr++ = val;
  return dest;
}

void* fl::memcpy (void *dest, const void *src, size_t len)
{
  char *d = (char*) dest;
  const char *s = (const char*) src;
  while (len--)
    *d++ = *s++;
  return dest;
}
