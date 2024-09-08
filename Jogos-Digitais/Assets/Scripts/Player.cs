using UnityEngine;

public class Player : MonoBehaviour
{
    public Movimento movimento { get; private set; }
    public SpriteRenderer spriteRenderer { get; private set; }

    public Sprite spriteDireitaParado;
    public Sprite spriteDireitaAndando1;
    public Sprite spriteDireitaAndando2;
    public Sprite spriteEsquerdaParado;
    public Sprite spriteEsquerdaAndando1;
    public Sprite spriteEsquerdaAndando2;
    public Sprite spriteCimaParado;
    public Sprite spriteCimaAndando1;
    public Sprite spriteCimaAndando2;
    public Sprite spriteBaixoParado;
    public Sprite spriteBaixoAndando1;
    public Sprite spriteBaixoAndando2;

    private Vector2 direction;
    private float animationTimer;
    private float rotationVelocity;

    private enum AnimationState { Idle, Walking }
    private AnimationState animationState;

    private void Awake()
    {
        this.movimento = GetComponent<Movimento>();
        this.spriteRenderer = GetComponent<SpriteRenderer>();
        spriteRenderer.sprite = spriteDireitaParado; // Inicializa a sprite do personagem como a sprite da direita parado
    }

    private void Update()
    {
        // Update direction
        if (Input.GetKeyDown(KeyCode.D) || Input.GetKeyDown(KeyCode.RightArrow))
        {
            direction = Vector2.right;
        }
        else if (Input.GetKeyDown(KeyCode.A) || Input.GetKeyDown(KeyCode.LeftArrow))
        {
            direction = Vector2.left;
        }
        else if (Input.GetKeyDown(KeyCode.W) || Input.GetKeyDown(KeyCode.UpArrow))
        {
            direction = Vector2.up;
        }
        else if (Input.GetKeyDown(KeyCode.S) || Input.GetKeyDown(KeyCode.DownArrow))
        {
            direction = Vector2.down;
        }

        // Update movement
        if (direction != Vector2.zero)
        {
            movimento.SetDirecao(direction);
            animationState = AnimationState.Walking;
        }
        else
        {
            animationState = AnimationState.Idle;
        }

        // Update animation
        switch (animationState)
        {
            case AnimationState.Idle:
                animationTimer = 0f;
                spriteRenderer.sprite = GetParadoSprite(direction);
                break;
            case AnimationState.Walking:
                animationTimer += Time.deltaTime;
                if (animationTimer > 0.5f)
                {
                    animationTimer = 0f;
                }
                spriteRenderer.sprite = GetAndandoSprite(direction, animationTimer);
                break;
        }

        // Smooth movement
        float smoothMovement = Mathf.Lerp(movimento.rgdb2D.velocity.x, direction.x * movimento.velocidade, 0.1f);
        movimento.rgdb2D.velocity = new Vector2(smoothMovement, movimento.rgdb2D.velocity.y);

    }

    private Sprite GetParadoSprite(Vector2 direction)
    {
        if (direction == Vector2.right)
            return spriteDireitaParado;
        else if (direction == Vector2.left)
            return spriteEsquerdaParado;
        else if (direction == Vector2.up)
            return spriteCimaParado;
        else if (direction == Vector2.down)
            return spriteBaixoParado;
        else
            return spriteDireitaParado;
    }

    private Sprite GetAndandoSprite(Vector2 direction, float animationTimer)
    {
        if (direction == Vector2.right)
            return animationTimer < 0.25f ? spriteDireitaAndando1 : spriteDireitaAndando2;
        else if (direction == Vector2.left)
            return animationTimer < 0.25f ? spriteEsquerdaAndando1 : spriteEsquerdaAndando2;
        else if (direction == Vector2.up)
            return animationTimer < 0.25f ? spriteCimaAndando1 : spriteCimaAndando2;
        else if (direction == Vector2.down)
            return animationTimer < 0.25f ? spriteBaixoAndando1 : spriteBaixoAndando2;
        else
            return spriteDireitaAndando1;
    }

    public void ResetState()
    {
        this.gameObject.SetActive(true);
        this.movimento.ResetState();
    }
}