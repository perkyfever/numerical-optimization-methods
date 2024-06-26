import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import re

def plot_projectile(trajectory_path: str, title: str, save_name: str = None):
    points = pd.read_csv(trajectory_path)
    if re.search('gsl', trajectory_path) is None:
        points = points.loc[points.index.values[::50]]

    x0, y0 = points.x.values[0], points.y.values[0]
    x_end, y_end = points.x.values[-1], points.y.values[-1]
    y_min_idx, y_max_idx = points.y.values.argmin(), points.y.values.argmax()

    fig, ax = plt.subplots(figsize=(10, 6))
    sns.lineplot(data=points, x='x', y='y', label="Projectile", c='b', ax=ax)
    # ground
    ax.hlines(y=y0, xmin=x0, xmax=x_end, colors='k', label="Ground", ls='--')
    # range
    ax.vlines(x=points.x.values[y_max_idx], ymin=points.y.values[y_min_idx], ymax=points.y.values[y_max_idx],
              label=f"Range = {points.y.values[y_max_idx]:.3f}", ls='--', colors='r')

    ax.set(xlabel='x-coordinate', ylabel='y-coordinate', title=title)
    ax.legend()
    ax.grid()
    fig.tight_layout()

    if isinstance(save_name, str):
        fig.savefig(fname=save_name, bbox_inches='tight')


if __name__ == "__main__":
    from os.path import join
    trajectory_paths = ['trajectory_optimal_range', 'trajectory_optimal_range_gsl',
                        'trajectory_optimal_height', 'trajectory_optimal_height_gsl']
    for name in trajectory_paths:
        save_name = join('img', f'{name}.png')
        trajectory_path = join('trajectory', f'{name}.csv')
        title_name = ''
        if re.search('gsl', name) is not None:
            title_name += 'GSL_'
        if re.search('range', name) is not None:
            title_name += 'Angle=26'
        if re.search('height', name) is not None:
            title_name += 'Angle=40'
        plot_projectile(trajectory_path=trajectory_path, title=f"{title_name}, y0=0", save_name=save_name)
