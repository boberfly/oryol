#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::_priv::d3d12Mesh
    @ingroup _priv
    @brief D3D12 implementation of class mesh
*/
#include "Gfx/Resource/meshBase.h"
#include "Gfx/d3d12/d3d12_decl.h"
#include "Gfx/d3d12/d3d12Config.h"

namespace Oryol {
namespace _priv {

class d3d12Mesh : public meshBase {
public:
    /// destructor
    ~d3d12Mesh();

    /// clear the object (called from meshFactory::DestroyResource())
    void Clear();

    static const int NumSlots = d3d12Config::NumFrames;
    struct buffer {
        buffer() : 
            updateFrameIndex(InvalidIndex),
            numSlots(1),
            activeSlot(0) {
            d3d12RenderBuffers.Fill(nullptr);
            d3d12UploadBuffers.Fill(nullptr);
        }
        uint64_t updateFrameIndex;
        uint8_t numSlots;
        uint8_t activeSlot;
        StaticArray<ID3D12Resource*,NumSlots> d3d12RenderBuffers;
        StaticArray<ID3D12Resource*,NumSlots> d3d12UploadBuffers;
    };
    static const int vb = 0;
    static const int ib = 1;
    StaticArray<buffer, 2> buffers;
};

} // namespace _priv
} // namespace Oryol
