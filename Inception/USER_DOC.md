# USER_DOC.md - User Documentation

## Overview

This document explains how to set up, run, and use the Inception WordPress infrastructure on Linux.
The stack includes:
- NGINX reverse proxy with TLS on port 443
- WordPress with PHP-FPM
- MariaDB database

## Services Provided

### NGINX
- Reverse proxy and TLS terminator
- Listens on port 443
- Serves WordPress PHP pages through `wordpress:9000`
- Generates self-signed certificates at startup using values from `.env`

### WordPress
- Runs WordPress core with PHP 7.4 FPM
- Uses WordPress CLI to download core and install the site on first startup
- Connects to MariaDB using environment variables and Docker secrets
- Stores files in the host bind-mounted directory `/home/$USER/data/wordpress`

### MariaDB
- Stores WordPress data in `/var/lib/mysql`
- Uses secrets for database and root passwords
- Persists data in `/home/$USER/data/mariadb`

---

## Getting Started

### 1. Prepare the project

```bash
cd ~/Inception
```

### 2. Copy the example environment file

```bash
cp srcs/.env_example srcs/.env
```

### 3. Edit `srcs/.env`

Update the values for your setup:

```bash
USERNAME=your_login
DOMAIN_NAME=your_login.42.fr
CERTS=/etc/nginx/ssl/your_login.crt
KEYOUT=/etc/nginx/ssl/your_login.key
MYSQL_USER=wordpress
MYSQL_DATABASE=wordpress
MYSQL_HOSTNAME=mariadb
WORDPRESS_TITLE="My Website"
WORDPRESS_ROOT_USERNAME=wpadmin
WORDPRESS_ROOT_EMAIL=admin@example.com
WORDPRESS_USER_USERNAME=subscriber
WORDPRESS_USER_EMAIL=user@example.com
```

### 4. Create required secrets files

```bash
mkdir -p srcs/secrets/maria_db
mkdir -p srcs/secrets/wordpress

echo -n "your_db_password" > srcs/secrets/maria_db/db_password.txt
echo -n "your_root_password" > srcs/secrets/maria_db/db_root_password.txt
echo -n "your_wordpress_user_pass" > srcs/secrets/wordpress/wp_user_password.txt
echo -n "your_wordpress_admin_pass" > srcs/secrets/wordpress/wp_root_password.txt
```

### 5. Start the services

```bash
make
```

The Makefile will:
- verify `srcs/.env` exists
- create host data directories under `/home/$USER/data/`
- verify required secret files exist
- build and launch containers via `docker-compose`

### 6. Open the website

Visit:

```text
https://your_login.42.fr
```

Visit the admin dashboard:

```text
https://your_login.42.fr/wp-admin
```

---

## Access and Credentials

### WordPress Login

The WordPress administrator username is defined in `srcs/.env` under `WORDPRESS_ROOT_USERNAME`.
The admin password is stored in:

```bash
srcs/secrets/wordpress/wp_root_password.txt
```

The subscriber user password is stored in:

```bash
srcs/secrets/wordpress/wp_user_password.txt
```

### Database Credentials

MariaDB credentials are stored in secrets and referenced by Docker Compose:

```bash
srcs/secrets/maria_db/db_password.txt
srcs/secrets/maria_db/db_root_password.txt
```

### Important Notes

- There is no `credentials.txt` file in this project.
- Do not commit `srcs/.env` or `srcs/secrets/` to git.
- The site uses self-signed TLS certificates, so the browser may warn you on first access.

---

## Managing the Infrastructure

### Stop containers

```bash
make down
```

### Stop containers and remove host data directories

```bash
make clean
```

### Full cleanup including images and secrets

```bash
make fclean
```

### Restart containers

```bash
make start
```

### Stop containers without removing volumes

```bash
make stop
```

---

## Health Checks

### Check running containers

```bash
docker ps
```

### Check logs

```bash
docker-compose -f srcs/docker-compose.yml logs -f nginx

docker-compose -f srcs/docker-compose.yml logs -f wordpress

docker-compose -f srcs/docker-compose.yml logs -f mariadb
```

### Test HTTPS access

```bash
curl -k https://your_login.42.fr
```

### Verify host persistence

```bash
ls -la /home/$USER/data/wordpress
ls -la /home/$USER/data/mariadb
```

---

## Troubleshooting

| Problem | Likely Cause | Fix |
|---|---|---|
| Connection refused | Containers not running | Run `make` and confirm `docker ps` |
| Bad gateway | WordPress not ready yet | Wait, then refresh browser |
| TLS warning | Self-signed certificate | Accept risk in browser |
| Secret file missing | `srcs/secrets/*` not created | Create missing file with password |
| 404 on PHP pages | NGINX config not updated | Ensure `.env` values are set and restart |

---

## More Information

- See `DEV_DOC.md` for developer and build details
- See `README.md` for project overview and architecture
