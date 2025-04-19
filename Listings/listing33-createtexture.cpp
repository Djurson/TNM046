void Texture::createTexture(const std::string& filename) {
    image_ = loadUncompressedTGA(filename);

    if (image_.data.empty()) {
        return;
    }

    if (textureID_ == 0) {
        glGenTextures(1, &textureID_);  // Create the texture ID if it does not exist
    }

    glBindTexture(GL_TEXTURE_2D, textureID_);
    // Set parameters to determine how the texture is resized
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Set parameters to determine how the texture wraps at edges
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Read the texture data from file and upload it to the GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_.width, image_.height, 0, image_.type,
                 GL_UNSIGNED_BYTE, image_.data.data());

    glEnable(GL_TEXTURE_2D);  // Required for glGenerateMipmap() to work
    glGenerateMipmap(GL_TEXTURE_2D);

    // Image data was copied to the GPU, release contents of the std::vector
    // When using clear() the std::vector would still hold on to the memory.
    image_.data = std::vector<GLubyte>();
}