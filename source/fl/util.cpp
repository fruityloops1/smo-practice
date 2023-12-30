#include <fl/util.h>
#include "al/collision/CollisionParts.h"
#include "al/collision/KCollisionServer.h"
#include "al/util.hpp"

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

void fl::fillTri(al::Triangle* tri, const al::CollisionParts &collisionParts, const al::KCPrismData *prismData, const al::KCPrismHeader *prismHeader) {
    al::KCollisionServer* collisionServer = collisionParts.mKCollisionServer;
    sead::Matrix34f baseMtx = collisionParts.mBaseMtx;

    sead::Vector3f faceNormal = *collisionServer->getFaceNormal(prismData, prismHeader);
    tri->mFaceNormal.x = faceNormal.x * baseMtx.m[0][0] + faceNormal.y * baseMtx.m[0][1] + faceNormal.z * baseMtx.m[0][2];
    tri->mFaceNormal.y = faceNormal.x * baseMtx.m[1][0] + faceNormal.y * baseMtx.m[1][1] + faceNormal.z * baseMtx.m[1][2];
    tri->mFaceNormal.z = faceNormal.x * baseMtx.m[2][0] + faceNormal.y * baseMtx.m[2][1] + faceNormal.z * baseMtx.m[2][2];
    al::normalize(&tri->mFaceNormal);

    sead::Vector3f verts[3];
    collisionServer->calcPosLocal(verts, prismData, 0, prismHeader);
    collisionServer->calcPosLocal(verts + 1, prismData, 1, prismHeader);
    collisionServer->calcPosLocal(verts + 2, prismData, 2, prismHeader);

    tri->mVerts[0].x = verts[0].x * baseMtx.m[0][0] + verts[0].y * baseMtx.m[0][1] + verts[0].z * baseMtx.m[0][2];
    tri->mVerts[0].y = verts[0].x * baseMtx.m[1][0] + verts[0].y * baseMtx.m[1][1] + verts[0].z * baseMtx.m[1][2];
    tri->mVerts[0].z = verts[0].x * baseMtx.m[2][0] + verts[0].y * baseMtx.m[2][1] + verts[0].z * baseMtx.m[2][2];

    tri->mVerts[1].x = verts[1].x * baseMtx.m[0][0] + verts[1].y * baseMtx.m[0][1] + verts[1].z * baseMtx.m[0][2];
    tri->mVerts[1].y = verts[1].x * baseMtx.m[1][0] + verts[1].y * baseMtx.m[1][1] + verts[1].z * baseMtx.m[1][2];
    tri->mVerts[1].z = verts[1].x * baseMtx.m[2][0] + verts[1].y * baseMtx.m[2][1] + verts[1].z * baseMtx.m[2][2];

    tri->mVerts[2].x = verts[2].x * baseMtx.m[0][0] + verts[2].y * baseMtx.m[0][1] + verts[2].z * baseMtx.m[0][2];
    tri->mVerts[2].y = verts[2].x * baseMtx.m[1][0] + verts[2].y * baseMtx.m[1][1] + verts[2].z * baseMtx.m[1][2];
    tri->mVerts[2].z = verts[2].x * baseMtx.m[2][0] + verts[2].y * baseMtx.m[2][1] + verts[2].z * baseMtx.m[2][2];
}
