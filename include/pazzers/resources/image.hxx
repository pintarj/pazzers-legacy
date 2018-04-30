
#ifndef PAZZERS_RESOURCES_IMAGE_HXX
#define PAZZERS_RESOURCES_IMAGE_HXX

#include <functional>
#include <string>
#include <SDL/SDL_video.h>

namespace pazzers
{
    namespace resources
    {
        class ImageView;

        /**
         * \brief Class that represents an image.
         *
         * Each image has an associated "SDL_surface".
         * */
        class Image
        {
        public:
            /**
             * \brief A view that covers the whole image.
             * */
            ImageView* const full_view;

            /**
             * \brief The SDL_surface associated with this image.
             * */
            SDL_Surface* const surface;

            /**
             * \brief Create a new Image associating it with a specified SDL_surface.
             * \param surface The SDL_surface to associate with.
             * */
            Image(SDL_Surface* surface);

            /**
             * \brief Create a new Image using a specific image file referenced by a filename.
             * \param file_name The filename that reference the image file.
             * */
            Image(const std::string& file_name);

            /**
             * \brief Release the used resources.
             * */
            virtual ~Image();

            /**
             * \brief Returns the image's width.
             * \return The image's width.
             * */
            int get_width() const;

            /**
             * \brief Returns the image's height.
             * \return The image's height.
             * */
            int get_height() const;

            /**
             * \brief Applies an image, using the specified image view associated with it, on this image on the specified
             *     offset.
             * \param view The view associated with the image to apply.
             * \param x The x offset on this image.
             * \param y The y offset on this image.
             * */
            void apply(const ImageView& view, int x, int y);

            /**
             * \brief Applies a specified image, using it's "full_view", on this image on the specified offset.
             * \param image The image to apply.
             * \param x The x offset on this image.
             * \param y The y offset on this image.
             * */
            void apply(const Image& image, int x, int y);

            /**
             * \brief Create a clone of this image.
             * \return The clone.
             *
             * The clone should be then deleted with "delete".
             * */
            Image* clone() const;

            /**
             * \brief Performs a per-pixel filter.
             * \param f The function will accept the x and y coordinates and then the values of the current pixel.
             *     The new values of the pixel have to be stored directly in the third argument.
             * */
            void filter(const std::function<void(int, int, std::uint8_t*)>& f);
        };

        /**
         * \brief Class that represents an image view (a portion of an image).
         * */
        class ImageView
        {
        public:
            /**
             * \brief The image that has this view associated.
             * */
            const Image& image;

            /**
             * \brief Creates an image view for the specified image and with the specified offset coordinates
             *     and dimensions.
             * \param image The image that will have this view associated.
             * \param x The x offset on the image.
             * \param y The y offset on the image.
             * \param width The width of the view.
             * \param width The height of the view.
             * */
            ImageView(const Image& image, int x, int y, int width, int height);

            /**
             * \brief Release the used resources.
             * */
            virtual ~ImageView();

            /**
             * \brief Returns the image's width.
             * \return The image's width.
             * */
            int get_width() const;

            /**
             * \brief Returns the image's height.
             * \return The image's height.
             * */
            int get_height() const;

            /**
             * \brief Applies an image, using the specified image view associated with it, on the image that has this view
             *     associated with using the relative coordinates of this view.
             * \param view The view associated with the image to apply.
             * \param x The x offset relative on this image's view.
             * \param y The y offset relative on this image's view.
             * */
            void apply(const ImageView& view, int x, int y);

            /**
             * \brief Applies an image, on the image that has this view associated with using the relative coordinates
             *     of this view.
             * \param view The image to apply.
             * \param x The x offset relative on this image's view.
             * \param y The y offset relative on this image's view.
             * */
            void apply(const Image& image, int x, int y);

        private:
            /**
             * \brief The rectangle that has stored the offset coordinates and dimensions.
             * */
            SDL_Rect rect;
        };
    }
}

#endif
