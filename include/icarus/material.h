#pragma once
#include "icarus/shader_program.h"
#include "icarus/texture.h"
namespace icrs {
    struct Material {
        ShaderProgram program;
        Texture texture;

        uint64_t render_state;

        Material(const std::string& texture_name, const std::string& program_name);

        void bind();
    };
}
