/**
 * Author: Alessio Placitelli
 * Contact: a.placitelli _@_ a2p.it
 *
 */
 
#ifndef _GPUImageTwoInputFilter_h_
#define _GPUImageTwoInputFilter_h_

#include "GPUImageFilter.h"
#include <string>


class GPUImageTwoInputFilter : public GPUImageFilter 
{
public:
    GPUImageTwoInputFilter();
    virtual ~GPUImageTwoInputFilter();

    void initWithFragmentShaderFromString(const std::string& fragmentShaderString);
    void initWithVertexShaderFromString(const std::string& vertexShaderString, const std::string& fragmentShaderString);
    void initializeAttributes();
    virtual void renderToTextureWithVertices(const GLfloat* vertices, const GLfloat* textureCoordinates, GLuint sourceTexture);

    // from GPUImageFilter
    gpu_int nextAvailableTextureIndex();
    void setInputTexture(GLuint newInputTexture, gpu_int textureIndex);
    void setInputSize(gpu_float_size newSize, gpu_int textureIndex);
    void setInputRotation(GPUImageRotationMode newInputRotation, gpu_int textureIndex);
    gpu_float_size rotatedSize(gpu_float_size sizeToRotate, gpu_int textureIndex);
    void newFrameReadyAtTime(gpu_time frameTime, gpu_int textureIndex);

    const static std::string kGPUImageTwoInputTextureVertexShaderString;

private:
    GLint filterSecondTextureCoordinateAttribute_;
    GLint filterInputTextureUniform2_;
    GPUImageRotationMode inputRotation2_;
    GLuint filterSourceTexture2_;
    gpu_time firstFrameTime_;
    gpu_time secondFrameTime_;
    
    bool hasSetFirstTexture_;
    bool hasReceivedFirstFrame_; 
    bool hasReceivedSecondFrame_; 
    bool firstFrameWasVideo_; 
    bool secondFrameWasVideo_;
};

#endif // _GPUImageTwoInputFilter_h_
