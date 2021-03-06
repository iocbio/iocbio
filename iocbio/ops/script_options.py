
__all__ = ['set_convolve_options',
           'get_fft_options_group',
           'set_regress_options',
           'get_regress_options_group',
           'get_apply_window_options_group',
           'set_apply_window_options',
           'set_apply_noise_options',
           'set_estimate_snr_options']

import os
from optparse import OptionGroup, NO_DEFAULT
from iocbio.script_options import set_formatter

def set_estimate_snr_options (parser):
    from ..io.script_options import get_microscope_options_group
    set_formatter (parser)
    parser.set_usage('%prog [options] [ -i INPUT_PATH ]')
    parser.set_description('Estimate signal to noise ratio from the INPUT_PATH images.')
    parser.add_option ('--input-path','-i',
                       type = 'file', metavar='PATH',
                       help = 'Specify input PATH of 3D images.'
                       )
    parser.add_option_group(get_regress_options_group (parser))
    parser.add_option_group(get_microscope_options_group (parser))


def set_apply_window_options (parser):
    from ..io.script_options import get_microscope_options_group
    set_formatter (parser)
    parser.set_usage('%prog [options] [ INPUT_PATH [OUTPUT_PATH]]')
    parser.set_description('Apply smooth window to INPUT_PATH scalar field.')
    parser.add_option ('--quiet', dest = 'verbose',
                       action = 'store_false', default=True,
                       help = 'Disable output messages.')
    parser.add_option ('--input-path','-i',
                       type = 'file', metavar='PATH',
                       help = 'Specify input PATH of 3D images.'
                       )
    parser.add_option ('--output-path','-o',
                       type = 'file', metavar='PATH',
                       help = 'Specify output PATH of 3D images.'
                       )
    get_apply_window_options_group(parser, group=parser)
    parser.add_option_group(get_microscope_options_group (parser))

def set_convolve_options(parser):
    from ..microscope.script_options import add_psflib_options
    set_formatter (parser)
    parser.set_usage('%prog [options] [ [-i] INPUT_PATH [ [-o] OUTPUT_PATH ] ]')
    parser.set_description('Convolve INPUT_PATH with KERNEL_PATH.')
    add_psflib_options(parser)
    parser.add_option ('--kernel-path','-k',
                       type = 'file', metavar='PATH',
                       help = 'Specify PATH to 3D images to be used as a kernel.'
                       )
    parser.add_option ('--input-path', '-i',
                       type = 'file', metavar='PATH',
                       help = 'Specify input PATH of 3D images.'
                       )
    parser.add_option ('--output-path', '-o',
                       type = 'file', metavar='PATH',
                       help = 'Specify output PATH of 3D images.'
                       )
    parser.add_option_group(get_fft_options_group (parser))

def get_regress_options_group(parser, group=None):
    if group is None:
        group = OptionGroup (parser, 'Regression options',
                             description = '''\
Specify options for applying regression.''')
        group.add_option('--regress', action='store_true',
                         help = 'Apply regress to input images.')
        group.add_option('--no-regress', action='store_false',
                         dest = 'regress',
                         help = 'See ``--regress`` option.')

    group.add_option('--method', dest='method',
                      choices = ['average', 'linear'],
                      default = 'linear',
                      help="Select smoothing method.")
    group.add_option('--kernel', dest='kernel',
                       choices = ['epanechnikov', 'uniform', 'triangular', 'quartic', 'triweight', 'tricube'],
                       default = 'uniform',
                       help="Select smoothing kernel.")

    group.add_option ('--boundary', dest='boundary',
                      choices = ['constant', 'finite', 'periodic', 'reflective'],
                      default = 'finite',
                      help="Specify boundary condition.")

    return group

def get_apply_window_options_group(parser, group=None):
    if group is None:
        group = OptionGroup (parser, 'Apply window options',
                             description = 'Specify options for applying window.')
        group.add_option('--apply-window', action='store_true',
                         help = 'Apply window to input images.')
        group.add_option('--no-apply-window', action='store_false',
                         dest = 'apply_window',
                         help = 'See ``--apply-window`` option.')


    group.add_option ('--smoothness',
                      choices = ['0','1','2','3'], default = '1', 
                      help = 'Specify smoothness parameter n, the window will be (2*n+1)x continuously differentiable.')
    group.add_option('--window-width',  metavar='FLOAT',
                     type = 'float',
                     help = 'Specify the width of a cutting window in minimal voxel size unit.')

    return group

def get_fft_options_group (parser):
    group = OptionGroup (parser, 'FFT algorithm options',
                         description = '''\
Specify options for FFT algorithm.''')
    group.add_option ('--float-type',
                      choices = ['single', 'double'], default = 'single',
                      help = 'Specify floating point number type to be used in FFT computations.')

    group.add_option ('--fftw-plan-flags',
                      choices = ['patient', 'measure', 'estimate', 'exhaustive'],
                      default = 'measure',
                      help = 'Specify FFTW plan flags.')
    group.add_option ('--fftw-threads',
                      type=int, default=1,
                      help = 'Specify the number of threads for FFTW plan.')

    return group

def set_regress_options (parser):
    from ..io.script_options import get_microscope_options_group, get_io_options_group
    set_formatter (parser)
    parser.set_usage ('%prog [options] [ [-i] INPUT_PATH [ [-o] OUTPUT_PATH]]')
    parser.set_description('Apply local regression methods to INPUT_PATH scalar field.')
    parser.add_option ('--quiet', dest='verbose', action='store_false',
                       help = 'Disable output messages.')
    parser.add_option ('--input-path','-i',
                       type = 'file', metavar='PATH',
                       help = 'Specify input PATH of 3D images.'
                       )
    parser.add_option ('--output-path','-o',
                       type = 'file', metavar='PATH',
                       help = 'Specify output PATH of 3D images.'
                       )
    parser.add_option ("--kernel-width", dest="kernel_width",
                       type = 'float',
                       help="Specify the width of kernel in minimal voxel size unit."
                       )
    parser.add_option ('--link-function',
                       choices = ['identity'], default='identity',
                       help="Specify link function to transform data before regression analysis.")

    get_regress_options_group (parser, group=parser)
    parser.add_option_group(get_io_options_group (parser))
    parser.add_option_group(get_microscope_options_group (parser))

def set_apply_noise_options (parser):
    parser.set_usage ('%prog [options] [ [-i] INPUT_PATH [ [-o] OUTPUT_PATH] ]')
    set_formatter (parser)
    parser.set_description('Apply noise to INPUT_PATH scalar field.')
    parser.add_option ('--quiet', dest = 'verbose',
                       action = 'store_false', default=True,
                       help = 'Disable output messages.')
    parser.add_option ('--input-path','-i',
                       type = 'file', metavar='PATH',
                       help = 'Specify input PATH of 3D images.'
                       )
    parser.add_option ('--output-path','-o',
                       type = 'file', metavar='PATH',
                       help = 'Specify output PATH of 3D images.'
                       )
    parser.add_option ("--noise-type", dest='noise_type',
                      choices = ['poisson'],
                      default = 'poisson',
                      help = 'Specify noise type.',
                      )
