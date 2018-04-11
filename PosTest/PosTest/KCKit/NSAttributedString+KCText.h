//
//  NSAttributedString+KCText.h
//  Jade
//
//  Created by king on 16/6/7.
//  Copyright © 2016年 KC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreText/CoreText.h>

#import "KCTextAttribute.h"
#import "KCTextRubyAnnotation.h"

@interface NSAttributedString (KCText)

- (NSData *)archiveToData;
+ (instancetype)unarchiveFromData:(NSData *)data;
@property (nonatomic, copy, readonly) NSDictionary *attributes;
- (NSDictionary *)attributesAtIndex:(NSUInteger)index;
- (id)attribute:(NSString *)attributeName atIndex:(NSUInteger)index;

@property (nonatomic, strong, readonly) UIFont *font;
- (UIFont *)fontAtIndex:(NSUInteger)index;

@property (nonatomic, strong, readonly) NSNumber *kern;
- (NSNumber *)kernAtIndex:(NSUInteger)index;

@property (nonatomic, strong, readonly) UIColor *color;
- (UIColor *)colorAtIndex:(NSUInteger)index;

@property (nonatomic, strong, readonly) UIColor *backgroundColor;
- (UIColor *)backgroundColorAtIndex:(NSUInteger)index;

@property (nonatomic, strong, readonly) NSNumber *strokeWidth;
- (NSNumber *)strokeWidthAtIndex:(NSUInteger)index;

@property (nonatomic, strong, readonly) UIColor *strokeColor;
- (UIColor *)strokeColorAtIndex:(NSUInteger)index;

@property (nonatomic, strong, readonly) NSShadow *shadow;
- (NSShadow *)shadowAtIndex:(NSUInteger)index;

@property (nonatomic, assign, readonly) NSUnderlineStyle strikethroughStyle;
- (NSUnderlineStyle)strikethroughStyleAtIndex:(NSUInteger)index;


@property (nonatomic, strong, readonly) UIColor *strikethroughColor;
- (UIColor *)strikethroughColorAtIndex:(NSUInteger)index;

@property (nonatomic, assign, readonly) NSUnderlineStyle underlineStyle;
- (NSUnderlineStyle)underlineStyleAtIndex:(NSUInteger)index;

@property (nonatomic, strong, readonly) UIColor *underlineColor;
- (UIColor *)underlineColorAtIndex:(NSUInteger)index;

@property (nonatomic, strong, readonly) NSNumber *ligature;
- (NSNumber *)ligatureAtIndex:(NSUInteger)index;

@property (nonatomic, strong, readonly) NSString *textEffect;
- (NSString *)textEffectAtIndex:(NSUInteger)index;

@property (nonatomic, strong, readonly) NSNumber *obliqueness;
- (NSNumber *)obliquenessAtIndex:(NSUInteger)index;

@property (nonatomic, strong, readonly) NSNumber *expansion;
- (NSNumber *)expansionAtIndex:(NSUInteger)index;

@property (nonatomic, strong, readonly) NSNumber *baselineOffset;
- (NSNumber *)baselineOffsetAtIndex:(NSUInteger)index;

@property (nonatomic, assign, readonly) BOOL verticalGlyphForm;
- (BOOL)verticalGlyphFormAtIndex:(NSUInteger)index;




@property (nonatomic, strong, readonly) NSString *language;
- (NSString *)languageAtIndex:(NSUInteger)index;

/**
 Specifies a bidirectional override or embedding. (read-only)
 
 @discussion See alse NSWritingDirection and NSWritingDirectionAttributeName.
 @discussion Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:7.0  YYKit:6.0
 */
@property (nonatomic, strong, readonly) NSArray *writingDirection;
- (NSArray *)writingDirectionAtIndex:(NSUInteger)index;

/**
 An NSParagraphStyle object which is used to specify things like
 line alignment, tab rulers, writing direction, etc. (read-only)
 
 @discussion Default is nil ([NSParagraphStyle defaultParagraphStyle]).
 @discussion Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, strong, readonly) NSParagraphStyle *paragraphStyle;
- (NSParagraphStyle *)paragraphStyleAtIndex:(NSUInteger)index;

#pragma mark - Get paragraph attribute as property
///=============================================================================
/// @name Get paragraph attribute as property
///=============================================================================

/**
 The text alignment (A wrapper for NSParagraphStyle). (read-only)
 
 @discussion Natural text alignment is realized as left or right alignment
 depending on the line sweep direction of the first script contained in the paragraph.
 @discussion Default is NSTextAlignmentNatural.
 @discussion Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readonly) NSTextAlignment alignment;
- (NSTextAlignment)alignmentAtIndex:(NSUInteger)index;

/**
 The mode that should be used to break lines (A wrapper for NSParagraphStyle). (read-only)
 
 @discussion This property contains the line break mode to be used laying out the paragraph's text.
 @discussion Default is NSLineBreakByWordWrapping.
 @discussion Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readonly) NSLineBreakMode lineBreakMode;
- (NSLineBreakMode)lineBreakModeAtIndex:(NSUInteger)index;

/**
 The distance in points between the bottom of one line fragment and the top of the next.
 (A wrapper for NSParagraphStyle) (read-only)
 
 @discussion This value is always nonnegative. This value is included in the line
 fragment heights in the layout manager.
 @discussion Default is 0.
 @discussion Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readonly) CGFloat lineSpacing;
- (CGFloat)lineSpacingAtIndex:(NSUInteger)index;

/**
 The space after the end of the paragraph (A wrapper for NSParagraphStyle). (read-only)
 
 @discussion This property contains the space (measured in points) added at the
 end of the paragraph to separate it from the following paragraph. This value must
 be nonnegative. The space between paragraphs is determined by adding the previous
 paragraph's paragraphSpacing and the current paragraph's paragraphSpacingBefore.
 @discussion Default is 0.
 @discussion Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readonly) CGFloat paragraphSpacing;
- (CGFloat)paragraphSpacingAtIndex:(NSUInteger)index;

/**
 The distance between the paragraph's top and the beginning of its text content.
 (A wrapper for NSParagraphStyle). (read-only)
 
 @discussion This property contains the space (measured in points) between the
 paragraph's top and the beginning of its text content.
 @discussion Default is 0.
 @discussion Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readonly) CGFloat paragraphSpacingBefore;
- (CGFloat)paragraphSpacingBeforeAtIndex:(NSUInteger)index;

/**
 The indentation of the first line (A wrapper for NSParagraphStyle). (read-only)
 
 @discussion This property contains the distance (in points) from the leading margin
 of a text container to the beginning of the paragraph's first line. This value
 is always nonnegative.
 @discussion Default is 0.
 @discussion Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readonly) CGFloat firstLineHeadIndent;
- (CGFloat)firstLineHeadIndentAtIndex:(NSUInteger)index;

/**
 The indentation of the receiver's lines other than the first. (A wrapper for NSParagraphStyle). (read-only)
 
 @discussion This property contains the distance (in points) from the leading margin
 of a text container to the beginning of lines other than the first. This value is
 always nonnegative.
 @discussion Default is 0.
 @discussion Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readonly) CGFloat headIndent;
- (CGFloat)headIndentAtIndex:(NSUInteger)index;

/**
 The trailing indentation (A wrapper for NSParagraphStyle). (read-only)
 
 @discussion If positive, this value is the distance from the leading margin
 (for example, the left margin in left-to-right text). If 0 or negative, it's the
 distance from the trailing margin.
 @discussion Default is 0.
 @discussion Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readonly) CGFloat tailIndent;
- (CGFloat)tailIndentAtIndex:(NSUInteger)index;

/**
 The receiver's minimum height (A wrapper for NSParagraphStyle). (read-only)
 
 @discussion This property contains the minimum height in points that any line in
 the receiver will occupy, regardless of the font size or size of any attached graphic.
 This value must be nonnegative.
 @discussion Default is 0.
 @discussion Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readonly) CGFloat minimumLineHeight;
- (CGFloat)minimumLineHeightAtIndex:(NSUInteger)index;

/**
 The receiver's maximum line height (A wrapper for NSParagraphStyle). (read-only)
 
 @discussion This property contains the maximum height in points that any line in
 the receiver will occupy, regardless of the font size or size of any attached graphic.
 This value is always nonnegative. Glyphs and graphics exceeding this height will
 overlap neighboring lines; however, a maximum height of 0 implies no line height limit.
 Although this limit applies to the line itself, line spacing adds extra space between adjacent lines.
 @discussion Default is 0 (no limit).
 @discussion Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readonly) CGFloat maximumLineHeight;
- (CGFloat)maximumLineHeightAtIndex:(NSUInteger)index;

/**
 The line height multiple (A wrapper for NSParagraphStyle). (read-only)
 
 @discussion This property contains the line break mode to be used laying out the paragraph's text.
 @discussion Default is 0 (no multiple).
 @discussion Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readonly) CGFloat lineHeightMultiple;
- (CGFloat)lineHeightMultipleAtIndex:(NSUInteger)index;

/**
 The base writing direction (A wrapper for NSParagraphStyle). (read-only)
 
 @discussion If you specify NSWritingDirectionNaturalDirection, the receiver resolves
 the writing direction to either NSWritingDirectionLeftToRight or NSWritingDirectionRightToLeft,
 depending on the direction for the user's `language` preference setting.
 @discussion Default is NSWritingDirectionNatural.
 @discussion Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readonly) NSWritingDirection baseWritingDirection;
- (NSWritingDirection)baseWritingDirectionAtIndex:(NSUInteger)index;

/**
 The paragraph's threshold for hyphenation. (A wrapper for NSParagraphStyle). (read-only)
 
 @discussion Valid values lie between 0.0 and 1.0 inclusive. Hyphenation is attempted
 when the ratio of the text width (as broken without hyphenation) to the width of the
 line fragment is less than the hyphenation factor. When the paragraph's hyphenation
 factor is 0.0, the layout manager's hyphenation factor is used instead. When both
 are 0.0, hyphenation is disabled.
 @discussion Default is 0.
 @discussion Get this property returns the first character's attribute.
 @since UIKit:6.0
 */
@property (nonatomic, assign, readonly) float hyphenationFactor;
- (float)hyphenationFactorAtIndex:(NSUInteger)index;

/**
 The document-wide default tab interval (A wrapper for NSParagraphStyle). (read-only)
 
 @discussion This property represents the default tab interval in points. Tabs after the
 last specified in tabStops are placed at integer multiples of this distance (if positive).
 @discussion Default is 0.
 @discussion Get this property returns the first character's attribute.
 @since CoreText:7.0  UIKit:7.0  YYKit:7.0
 */
@property (nonatomic, assign, readonly) CGFloat defaultTabInterval;
- (CGFloat)defaultTabIntervalAtIndex:(NSUInteger)index;

/**
 An array of NSTextTab objects representing the receiver's tab stops.
 (A wrapper for NSParagraphStyle). (read-only)
 
 @discussion The NSTextTab objects, sorted by location, define the tab stops for
 the paragraph style.
 @discussion Default is 12 TabStops with 28.0 tab interval.
 @discussion Get this property returns the first character's attribute.
 @since CoreText:7.0  UIKit:7.0  YYKit:7.0
 */
@property (nonatomic, copy, readonly) NSArray *tabStops;
- (NSArray *)tabStopsAtIndex:(NSUInteger)index;

#pragma mark - Get KCText attribute as property
///=============================================================================
/// @name Get KCText attribute as property
///=============================================================================

/**
 The text shadow. (read-only)
 
 @discussion Default value is nil (no shadow).
 @discussion Get this property returns the first character's attribute.
 @since YYKit:6.0
 */
@property (nonatomic, strong, readonly) KCTextShadow *textShadow;
- (KCTextShadow *)textShadowAtIndex:(NSUInteger)index;

/**
 The text inner shadow. (read-only)
 
 @discussion Default value is nil (no shadow).
 @discussion Get this property returns the first character's attribute.
 @since YYKit:6.0
 */
@property (nonatomic, strong, readonly) KCTextShadow *textInnerShadow;
- (KCTextShadow *)textInnerShadowAtIndex:(NSUInteger)index;

/**
 The text underline. (read-only)
 
 @discussion Default value is nil (no underline).
 @discussion Get this property returns the first character's attribute.
 @since YYKit:6.0
 */
@property (nonatomic, strong, readonly) KCTextDecoration *textUnderline;
- (KCTextDecoration *)textUnderlineAtIndex:(NSUInteger)index;

/**
 The text strikethrough. (read-only)
 
 @discussion Default value is nil (no strikethrough).
 @discussion Get this property returns the first character's attribute.
 @since YYKit:6.0
 */
@property (nonatomic, strong, readonly) KCTextDecoration *textStrikethrough;
- (KCTextDecoration *)textStrikethroughAtIndex:(NSUInteger)index;

/**
 The text border. (read-only)
 
 @discussion Default value is nil (no border).
 @discussion Get this property returns the first character's attribute.
 @since YYKit:6.0
 */
@property (nonatomic, strong, readonly) KCTextBorder *textBorder;
- (KCTextBorder *)textBorderAtIndex:(NSUInteger)index;

/**
 The text background border. (read-only)
 
 @discussion Default value is nil (no background border).
 @discussion Get this property returns the first character's attribute.
 @since YYKit:6.0
 */
@property (nonatomic, strong, readonly) KCTextBorder *textBackgroundBorder;
- (KCTextBorder *)textBackgroundBorderAtIndex:(NSUInteger)index;

/**
 The glyph transform. (read-only)
 
 @discussion Default value is CGAffineTransformIdentity (no transform).
 @discussion Get this property returns the first character's attribute.
 @since YYKit:6.0
 */
@property (nonatomic, assign, readonly) CGAffineTransform textGlyphTransform;
- (CGAffineTransform)textGlyphTransformAtIndex:(NSUInteger)index;


#pragma mark - Query for KCText
///=============================================================================
/// @name Query for KCText
///=============================================================================

/**
 Returns the plain text from a range.
 If there's `KCTextBackedStringAttributeName` attribute, the backed string will
 replace the attributed string range.
 
 @param range A range in receiver.
 @return The plain text.
 */
- (NSString *)plainTextForRange:(NSRange)range;


#pragma mark - Create attachment string for KCText
///=============================================================================
/// @name Create attachment string for KCText
///=============================================================================

/**
 Creates and returns an attachment.
 
 @param content      The attachment (UIImage/UIView/CALayer).
 @param contentMode  The attachment's content mode.
 @param width        The attachment's container width in layout.
 @param ascent       The attachment's container ascent in layout.
 @param descent      The attachment's container descent in layout.
 
 @return An attributed string, or nil if an error occurs.
 @since YYKit:6.0
 */
+ (NSMutableAttributedString *)attachmentStringWithContent:(id)content
                                               contentMode:(UIViewContentMode)contentMode
                                                     width:(CGFloat)width
                                                    ascent:(CGFloat)ascent
                                                   descent:(CGFloat)descent;

/**
 Creates and returns an attachment.
 
 
 Example: ContentMode:bottom Alignment:Top.
 
 The text      The attachment holder
 ↓                ↓
 ─────────┌──────────────────────┐───────
 / \   │                      │ / ___|
 / _ \  │                      │| |
 / ___ \ │                      │| |___     ←── The text line
 /_/   \_\│    ██████████████    │ \____|
 ─────────│    ██████████████    │───────
 │    ██████████████    │
 │    ██████████████ ←───────────────── The attachment content
 │    ██████████████    │
 └──────────────────────┘
 
 @param content        The attachment (UIImage/UIView/CALayer).
 @param contentMode    The attachment's content mode in attachment holder
 @param attachmentSize The attachment holder's size in text layout.
 @param fontSize       The attachment will align to this font.
 @param alignment      The attachment holder's alignment to text line.
 
 @return An attributed string, or nil if an error occurs.
 @since KCText:6.0
 */
+ (NSMutableAttributedString *)attachmentStringWithContent:(id)content
                                               contentMode:(UIViewContentMode)contentMode
                                            attachmentSize:(CGSize)attachmentSize
                                               alignToFont:(UIFont *)font
                                                 alignment:(KCTextVerticalAlignment)alignment;

/**
 Creates and returns an attahment from a fourquare image as if it was an emoji.
 
 @param image     A fourquare image.
 @param fontSize  The font size.
 
 @return An attributed string, or nil if an error occurs.
 @since YYKit:6.0
 */
+ (NSMutableAttributedString *)attachmentStringWithEmojiImage:(UIImage *)image fontSize:(CGFloat)fontSize;


#pragma mark - Utility
///=============================================================================
/// @name Utility
///=============================================================================

/**
 Returns NSMakeRange(0, self.length).
 */
- (NSRange)rangeOfAll;

/**
 If YES, it share the same attribute in entire text range.
 */
- (BOOL)isSharedAttributesInAllRange;

/**
 If YES, it can be drawn with the [drawWithRect:options:context:] method or displayed with UIKit.
 If NO, it should be drawn with CoreText or KCText.
 
 @discussion If the method returns NO, it means that there's at least one attribute
 which is not supported by UIKit (such as CTParagraphStyleRef). If display this string
 in UIKit, it may lose some attribute, or even crash the app.
 */
- (BOOL)canDrawWithUIKit;

@end







/**
 Set pre-defined attributes to attributed string.
 All properties defined in UIKit, CoreText and KCText are included.
 */
@interface NSMutableAttributedString (KCText)

#pragma mark - Set character attribute
///=============================================================================
/// @name Set character attribute
///=============================================================================

/**
 Sets the attributes to the entire text string.
 
 @discussion The old attributes will be removed.
 
 @param attributes  A dictionary containing the attributes to set, or nil to remove all attributes.
 */
- (void)setAttributes:(NSDictionary *)attributes;

/**
 Sets an attribute with the given name and value to the entire text string.
 
 @param name   A string specifying the attribute name.
 @param value  The attribute value associated with name. Pass `nil` or `NSNull` to
 remove the attribute.
 */
- (void)setAttribute:(NSString *)name value:(id)value;

/**
 Sets an attribute with the given name and value to the characters in the specified range.
 
 @param name   A string specifying the attribute name.
 @param value  The attribute value associated with name. Pass `nil` or `NSNull` to
 remove the attribute.
 @param range  The range of characters to which the specified attribute/value pair applies.
 */
- (void)setAttribute:(NSString *)name value:(id)value range:(NSRange)range;

/**
 Removes all attributes in the specified range.
 
 @param range  The range of characters.
 */
- (void)removeAttributesInRange:(NSRange)range;


#pragma mark - Set character attribute as property
///=============================================================================
/// @name Set character attribute as property
///=============================================================================

/**
 The font of the text.
 
 @discussion Default is Helvetica (Neue) 12.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:3.2  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, strong, readwrite) UIFont *font;
- (void)setFont:(UIFont *)font range:(NSRange)range;

/**
 A kerning adjustment.
 
 @discussion Default is standard kerning. The kerning attribute indicate how many
 points the following character should be shifted from its default offset as
 defined by the current character's font in points; a positive kern indicates a
 shift farther along and a negative kern indicates a shift closer to the current
 character. If this attribute is not present, standard kerning will be used.
 If this attribute is set to 0.0, no kerning will be done at all.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:3.2  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, strong, readwrite) NSNumber *kern;
- (void)setKern:(NSNumber *)kern range:(NSRange)range;

/**
 The foreground color.
 
 @discussion Default is Black.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:3.2  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, strong, readwrite) UIColor *color;
- (void)setColor:(UIColor *)color range:(NSRange)range;

/**
 The background color.
 
 @discussion Default is nil (or no background).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since UIKit:6.0
 */
@property (nonatomic, strong, readwrite) UIColor *backgroundColor;
- (void)setBackgroundColor:(UIColor *)backgroundColor range:(NSRange)range;

/**
 The stroke width.
 
 @discussion Default value is 0.0 (no stroke). This attribute, interpreted as
 a percentage of font point size, controls the text drawing mode: positive
 values effect drawing with stroke only; negative values are for stroke and fill.
 A typical value for outlined text is 3.0.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:3.2  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, strong, readwrite) NSNumber *strokeWidth;
- (void)setStrokeWidth:(NSNumber *)strokeWidth range:(NSRange)range;

/**
 The stroke color.
 
 @discussion Default value is nil (same as foreground color).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:3.2  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, strong, readwrite) UIColor *strokeColor;
- (void)setStrokeColor:(UIColor *)strokeColor range:(NSRange)range;

/**
 The text shadow.
 
 @discussion Default value is nil (no shadow).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, strong, readwrite) NSShadow *shadow;
- (void)setShadow:(NSShadow *)shadow range:(NSRange)range;

/**
 The strikethrough style.
 
 @discussion Default value is NSUnderlineStyleNone (no strikethrough).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since UIKit:6.0
 */
@property (nonatomic, assign, readwrite) NSUnderlineStyle strikethroughStyle;
- (void)setStrikethroughStyle:(NSUnderlineStyle)strikethroughStyle range:(NSRange)range;

/**
 The strikethrough color.
 
 @discussion Default value is nil (same as foreground color).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since UIKit:7.0
 */
@property (nonatomic, strong, readwrite) UIColor *strikethroughColor;
- (void)setStrikethroughColor:(UIColor *)strikethroughColor range:(NSRange)range NS_AVAILABLE_IOS(7_0);

/**
 The underline style.
 
 @discussion Default value is NSUnderlineStyleNone (no underline).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:3.2  UIKit:6.0
 */
@property (nonatomic, assign, readwrite) NSUnderlineStyle underlineStyle;
- (void)setUnderlineStyle:(NSUnderlineStyle)underlineStyle range:(NSRange)range;

/**
 The underline color.
 
 @discussion Default value is nil (same as foreground color).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:3.2  UIKit:7.0
 */
@property (nonatomic, strong, readwrite) UIColor *underlineColor;
- (void)setUnderlineColor:(UIColor *)underlineColor range:(NSRange)range;

/**
 Ligature formation control.
 
 @discussion Default is int value 1. The ligature attribute determines what kinds
 of ligatures should be used when displaying the string. A value of 0 indicates
 that only ligatures essential for proper rendering of text should be used,
 1 indicates that standard ligatures should be used, and 2 indicates that all
 available ligatures should be used. Which ligatures are standard depends on the
 script and possibly the font.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:3.2  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, strong, readwrite) NSNumber *ligature;
- (void)setLigature:(NSNumber *)ligature range:(NSRange)range;

/**
 The text effect.
 
 @discussion Default is nil (no effect). The only currently supported value
 is NSTextEffectLetterpressStyle.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since UIKit:7.0
 */
@property (nonatomic, strong, readwrite) NSString *textEffect;
- (void)setTextEffect:(NSString *)textEffect range:(NSRange)range NS_AVAILABLE_IOS(7_0);

/**
 The skew to be applied to glyphs.
 
 @discussion Default is 0 (no skew).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since UIKit:7.0
 */
@property (nonatomic, strong, readwrite) NSNumber *obliqueness;
- (void)setObliqueness:(NSNumber *)obliqueness range:(NSRange)range NS_AVAILABLE_IOS(7_0);

/**
 The log of the expansion factor to be applied to glyphs.
 
 @discussion Default is 0 (no expansion).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since UIKit:7.0
 */
@property (nonatomic, strong, readwrite) NSNumber *expansion;
- (void)setExpansion:(NSNumber *)expansion range:(NSRange)range NS_AVAILABLE_IOS(7_0);

/**
 The character's offset from the baseline, in points.
 
 @discussion Default is 0.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since UIKit:7.0
 */
@property (nonatomic, strong, readwrite) NSNumber *baselineOffset;
- (void)setBaselineOffset:(NSNumber *)baselineOffset range:(NSRange)range NS_AVAILABLE_IOS(7_0);

/**
 Glyph orientation control.
 
 @discussion Default is NO. A value of NO indicates that horizontal glyph forms
 are to be used, YES indicates that vertical glyph forms are to be used.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:4.3  YYKit:6.0
 */
@property (nonatomic, assign, readwrite) BOOL verticalGlyphForm;
- (void)setVerticalGlyphForm:(BOOL)verticalGlyphForm range:(NSRange)range;

/**
 Specifies text language.
 
 @discussion Value must be a NSString containing a locale identifier. Default is
 unset. When this attribute is set to a valid identifier, it will be used to select
 localized glyphs (if supported by the font) and locale-specific line breaking rules.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:7.0  YYKit:7.0
 */
@property (nonatomic, strong, readwrite) NSString *language;
- (void)setLanguage:(NSString *)language range:(NSRange)range NS_AVAILABLE_IOS(7_0);

/**
 Specifies a bidirectional override or embedding.
 
 @discussion See alse NSWritingDirection and NSWritingDirectionAttributeName.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:7.0  YYKit:6.0
 */
@property (nonatomic, strong, readwrite) NSArray *writingDirection;
- (void)setWritingDirection:(NSArray *)writingDirection range:(NSRange)range;

/**
 An NSParagraphStyle object which is used to specify things like
 line alignment, tab rulers, writing direction, etc.
 
 @discussion Default is nil ([NSParagraphStyle defaultParagraphStyle]).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, strong, readwrite) NSParagraphStyle *paragraphStyle;
- (void)setParagraphStyle:(NSParagraphStyle *)paragraphStyle range:(NSRange)range;


#pragma mark - Set paragraph attribute as property
///=============================================================================
/// @name Set paragraph attribute as property
///=============================================================================

/**
 The text alignment (A wrapper for NSParagraphStyle).
 
 @discussion Natural text alignment is realized as left or right alignment
 depending on the line sweep direction of the first script contained in the paragraph.
 @discussion Default is NSTextAlignmentNatural.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readwrite) NSTextAlignment alignment;
- (void)setAlignment:(NSTextAlignment)alignment range:(NSRange)range;

/**
 The mode that should be used to break lines (A wrapper for NSParagraphStyle).
 
 @discussion This property contains the line break mode to be used laying out the paragraph's text.
 @discussion Default is NSLineBreakByWordWrapping.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readwrite) NSLineBreakMode lineBreakMode;
- (void)setLineBreakMode:(NSLineBreakMode)lineBreakMode range:(NSRange)range;

/**
 The distance in points between the bottom of one line fragment and the top of the next.
 (A wrapper for NSParagraphStyle)
 
 @discussion This value is always nonnegative. This value is included in the line
 fragment heights in the layout manager.
 @discussion Default is 0.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readwrite) CGFloat lineSpacing;
- (void)setLineSpacing:(CGFloat)lineSpacing range:(NSRange)range;

/**
 The space after the end of the paragraph (A wrapper for NSParagraphStyle).
 
 @discussion This property contains the space (measured in points) added at the
 end of the paragraph to separate it from the following paragraph. This value must
 be nonnegative. The space between paragraphs is determined by adding the previous
 paragraph's paragraphSpacing and the current paragraph's paragraphSpacingBefore.
 @discussion Default is 0.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readwrite) CGFloat paragraphSpacing;
- (void)setParagraphSpacing:(CGFloat)paragraphSpacing range:(NSRange)range;

/**
 The distance between the paragraph's top and the beginning of its text content.
 (A wrapper for NSParagraphStyle).
 
 @discussion This property contains the space (measured in points) between the
 paragraph's top and the beginning of its text content.
 @discussion Default is 0.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readwrite) CGFloat paragraphSpacingBefore;
- (void)setParagraphSpacingBefore:(CGFloat)paragraphSpacingBefore range:(NSRange)range;

/**
 The indentation of the first line (A wrapper for NSParagraphStyle).
 
 @discussion This property contains the distance (in points) from the leading margin
 of a text container to the beginning of the paragraph's first line. This value
 is always nonnegative.
 @discussion Default is 0.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readwrite) CGFloat firstLineHeadIndent;
- (void)setFirstLineHeadIndent:(CGFloat)firstLineHeadIndent range:(NSRange)range;

/**
 The indentation of the receiver's lines other than the first. (A wrapper for NSParagraphStyle).
 
 @discussion This property contains the distance (in points) from the leading margin
 of a text container to the beginning of lines other than the first. This value is
 always nonnegative.
 @discussion Default is 0.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readwrite) CGFloat headIndent;
- (void)setHeadIndent:(CGFloat)headIndent range:(NSRange)range;

/**
 The trailing indentation (A wrapper for NSParagraphStyle).
 
 @discussion If positive, this value is the distance from the leading margin
 (for example, the left margin in left-to-right text). If 0 or negative, it's the
 distance from the trailing margin.
 @discussion Default is 0.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readwrite) CGFloat tailIndent;
- (void)setTailIndent:(CGFloat)tailIndent range:(NSRange)range;

/**
 The receiver's minimum height (A wrapper for NSParagraphStyle).
 
 @discussion This property contains the minimum height in points that any line in
 the receiver will occupy, regardless of the font size or size of any attached graphic.
 This value must be nonnegative.
 @discussion Default is 0.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readwrite) CGFloat minimumLineHeight;
- (void)setMinimumLineHeight:(CGFloat)minimumLineHeight range:(NSRange)range;

/**
 The receiver's maximum line height (A wrapper for NSParagraphStyle).
 
 @discussion This property contains the maximum height in points that any line in
 the receiver will occupy, regardless of the font size or size of any attached graphic.
 This value is always nonnegative. Glyphs and graphics exceeding this height will
 overlap neighboring lines; however, a maximum height of 0 implies no line height limit.
 Although this limit applies to the line itself, line spacing adds extra space between adjacent lines.
 @discussion Default is 0 (no limit).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readwrite) CGFloat maximumLineHeight;
- (void)setMaximumLineHeight:(CGFloat)maximumLineHeight range:(NSRange)range;

/**
 The line height multiple (A wrapper for NSParagraphStyle).
 
 @discussion This property contains the line break mode to be used laying out the paragraph's text.
 @discussion Default is 0 (no multiple).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readwrite) CGFloat lineHeightMultiple;
- (void)setLineHeightMultiple:(CGFloat)lineHeightMultiple range:(NSRange)range;

/**
 The base writing direction (A wrapper for NSParagraphStyle).
 
 @discussion If you specify NSWritingDirectionNaturalDirection, the receiver resolves
 the writing direction to either NSWritingDirectionLeftToRight or NSWritingDirectionRightToLeft,
 depending on the direction for the user's `language` preference setting.
 @discussion Default is NSWritingDirectionNatural.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:6.0  UIKit:6.0  YYKit:6.0
 */
@property (nonatomic, assign, readwrite) NSWritingDirection baseWritingDirection;
- (void)setBaseWritingDirection:(NSWritingDirection)baseWritingDirection range:(NSRange)range;

/**
 The paragraph's threshold for hyphenation. (A wrapper for NSParagraphStyle).
 
 @discussion Valid values lie between 0.0 and 1.0 inclusive. Hyphenation is attempted
 when the ratio of the text width (as broken without hyphenation) to the width of the
 line fragment is less than the hyphenation factor. When the paragraph's hyphenation
 factor is 0.0, the layout manager's hyphenation factor is used instead. When both
 are 0.0, hyphenation is disabled.
 @discussion Default is 0.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since UIKit:6.0
 */
@property (nonatomic, assign, readwrite) float hyphenationFactor;
- (void)setHyphenationFactor:(float)hyphenationFactor range:(NSRange)range;

/**
 The document-wide default tab interval (A wrapper for NSParagraphStyle).
 
 @discussion This property represents the default tab interval in points. Tabs after the
 last specified in tabStops are placed at integer multiples of this distance (if positive).
 @discussion Default is 0.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:7.0  UIKit:7.0  YYKit:7.0
 */
@property (nonatomic, assign, readwrite) CGFloat defaultTabInterval;
- (void)setDefaultTabInterval:(CGFloat)defaultTabInterval range:(NSRange)range NS_AVAILABLE_IOS(7_0);

/**
 An array of NSTextTab objects representing the receiver's tab stops.
 (A wrapper for NSParagraphStyle).
 
 @discussion The NSTextTab objects, sorted by location, define the tab stops for
 the paragraph style.
 @discussion Default is 12 TabStops with 28.0 tab interval.
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since CoreText:7.0  UIKit:7.0  YYKit:7.0
 */
@property (nonatomic, copy, readwrite) NSArray *tabStops;
- (void)setTabStops:(NSArray *)tabStops range:(NSRange)range NS_AVAILABLE_IOS(7_0);

#pragma mark - Set KCText attribute as property
///=============================================================================
/// @name Set KCText attribute as property
///=============================================================================

/**
 The text shadow.
 
 @discussion Default value is nil (no shadow).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since YYKit:6.0
 */
@property (nonatomic, strong, readwrite) KCTextShadow *textShadow;
- (void)setTextShadow:(KCTextShadow *)textShadow range:(NSRange)range;

/**
 The text inner shadow.
 
 @discussion Default value is nil (no shadow).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since YYKit:6.0
 */
@property (nonatomic, strong, readwrite) KCTextShadow *textInnerShadow;
- (void)setTextInnerShadow:(KCTextShadow *)textInnerShadow range:(NSRange)range;

/**
 The text underline.
 
 @discussion Default value is nil (no underline).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since YYKit:6.0
 */
@property (nonatomic, strong, readwrite) KCTextDecoration *textUnderline;
- (void)setTextUnderline:(KCTextDecoration *)textUnderline range:(NSRange)range;

/**
 The text strikethrough.
 
 @discussion Default value is nil (no strikethrough).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since YYKit:6.0
 */
@property (nonatomic, strong, readwrite) KCTextDecoration *textStrikethrough;
- (void)setTextStrikethrough:(KCTextDecoration *)textStrikethrough range:(NSRange)range;

/**
 The text border.
 
 @discussion Default value is nil (no border).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since YYKit:6.0
 */
@property (nonatomic, strong, readwrite) KCTextBorder *textBorder;
- (void)setTextBorder:(KCTextBorder *)textBorder range:(NSRange)range;

/**
 The text background border.
 
 @discussion Default value is nil (no background border).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since YYKit:6.0
 */
@property (nonatomic, strong, readwrite) KCTextBorder *textBackgroundBorder;
- (void)setTextBackgroundBorder:(KCTextBorder *)textBackgroundBorder range:(NSRange)range;

/**
 The glyph transform.
 
 @discussion Default value is CGAffineTransformIdentity (no transform).
 @discussion Set this property applies to the entire text string.
 Get this property returns the first character's attribute.
 @since YYKit:6.0
 */
@property (nonatomic, assign, readwrite) CGAffineTransform textGlyphTransform;
- (void)setTextGlyphTransform:(CGAffineTransform)textGlyphTransform range:(NSRange)range;


#pragma mark - Set discontinuous attribute for range
///=============================================================================
/// @name Set discontinuous attribute for range
///=============================================================================

- (void)setSuperscript:(NSNumber *)superscript range:(NSRange)range;
- (void)setGlyphInfo:(CTGlyphInfoRef)glyphInfo range:(NSRange)range;
- (void)setCharacterShape:(NSNumber *)characterShape range:(NSRange)range;
- (void)setRunDelegate:(CTRunDelegateRef)runDelegate range:(NSRange)range;
- (void)setBaselineClass:(CFStringRef)baselineClass range:(NSRange)range;
- (void)setBaselineInfo:(CFDictionaryRef)baselineInfo range:(NSRange)range;
- (void)setBaselineReferenceInfo:(CFDictionaryRef)referenceInfo range:(NSRange)range;
- (void)setRubyAnnotation:(CTRubyAnnotationRef)ruby range:(NSRange)range NS_AVAILABLE_IOS(8_0);
- (void)setAttachment:(NSTextAttachment *)attachment range:(NSRange)range NS_AVAILABLE_IOS(7_0);
- (void)setLink:(id)link range:(NSRange)range NS_AVAILABLE_IOS(7_0);
- (void)setTextBackedString:(KCTextBackedString *)textBackedString range:(NSRange)range;
- (void)setTextBinding:(KCTextBinding *)textBinding range:(NSRange)range;
- (void)setTextAttachment:(KCTextAttachment *)textAttachment range:(NSRange)range;
- (void)setTextHighlight:(KCTextHighlight *)textHighlight range:(NSRange)range;
- (void)setTextBlockBorder:(KCTextBorder *)textBlockBorder range:(NSRange)range;
- (void)setTextRubyAnnotation:(KCTextRubyAnnotation *)ruby range:(NSRange)range NS_AVAILABLE_IOS(8_0);

#pragma mark - Utilities
///=============================================================================
/// @name Utilities
///=============================================================================

/**
 Inserts into the receiver the characters of a given string at a given location.
 The new string inherit the attributes of the first replaced character from location.
 
 @param string  The string to insert into the receiver, must not be nil.
 @param location The location at which string is inserted. The location must not
 exceed the bounds of the receiver.
 @throw Raises an NSRangeException if the location out of bounds.
 */
- (void)insertString:(NSString *)string atIndex:(NSUInteger)location;

/**
 Adds to the end of the receiver the characters of a given string.
 The new string inherit the attributes of the receiver's tail.
 
 @param string  The string to append to the receiver, must not be nil.
 */
- (void)appendString:(NSString *)string;

/**
 Set foreground color with [UIColor clearColor] in joined-emoji range.
 Emoji drawing will not be affected by the foreground color.
 
 @discussion In iOS 8.3, Apple releases some new diversified emojis.
 There's some single emoji which can be assembled to a new 'joined-emoji'.
 The joiner is unicode character 'ZERO WIDTH JOINER' (U+200D).
 For example: 👨👩👧👧 -> 👨‍👩‍👧‍👧.
 
 When there are more than 5 'joined-emoji' in a same CTLine, CoreText may render some
 extra glyphs above the emoji. It's a bug in CoreText, try this method to avoid.
 This bug is fixed in iOS 9.
 */
- (void)setClearColorToJoinedEmoji;

/**
 Removes all discontinuous attributes in a specified range.
 See `allDiscontinuousAttributeKeys`.
 
 @param range A text range.
 */
- (void)removeDiscontinuousAttributesInRange:(NSRange)range;

/**
 Returns all discontinuous attribute keys, such as RunDelegate/Attachment/Ruby.
 
 @discussion These attributes can only set to a specified range of text, and
 should not extend to other range when editing text.
 */
+ (NSArray *)allDiscontinuousAttributeKeys;








@end
